#pragma once
#ifndef IOBASE_
#define IOBASE_

#include <map>
#include <fstream>
#include <string>
#include "safe_ptr.h"

class BankIOBase
{
protected:
	//bind file with lock
	static std::unordered_map<std::string, sf::default_contention_free_shared_mutex> file_mutex;
	static sf::default_contention_free_shared_mutex mapLock;

	class MapGuard
	{
	private:
		std::string name;
	public:
		MapGuard() = delete;
		MapGuard(const MapGuard&) = delete;
		auto operator =(const MapGuard&) = delete;

		MapGuard(const std::string& name): name(name)
		{
			mapLock.lock();
			file_mutex[name].lock();
			mapLock.unlock();
		}

		~MapGuard()
		{
			mapLock.lock();
			file_mutex[name].unlock();
			mapLock.unlock();
		}
	};

	class MapSharedGuard
	{
	private:
		std::string name;
	public:
		MapSharedGuard() = delete;
		MapSharedGuard(const MapSharedGuard&) = delete;
		auto operator =(const MapSharedGuard&) = delete;

		MapSharedGuard(const std::string& name) : name(name)
		{
			mapLock.lock();
			file_mutex[name].lock_shared();
			mapLock.unlock();
		}

		~MapSharedGuard()
		{
			mapLock.lock();
			file_mutex[name].unlock_shared();
			mapLock.unlock();
		}
	};


	std::fstream fs{};
	std::string name;

	BankIOBase() = default;

	explicit BankIOBase(std::string name) : name(std::move(name))
	{
	}

public:
	BankIOBase(const BankIOBase&) = delete;
	BankIOBase(BankIOBase&&) = delete;

	virtual ~BankIOBase() = default;
};

inline std::unordered_map<std::string, sf::contention_free_shared_mutex<>> BankIOBase::file_mutex = {};
inline sf::default_contention_free_shared_mutex BankIOBase::mapLock;

#endif


#ifndef SAVER_
#define SAVER_


class Saver : public BankIOBase
{
private:
	static bool status;
	std::ios::openmode mode;

public:
	explicit Saver(std::string fileName, const std::ios::openmode& mode = std::ios::app) :
		BankIOBase(std::move(fileName)),
		mode(mode)
	{
	}

	Saver(const Saver&) = delete;

	auto operator=(const Saver&) -> void = delete;

	~Saver() override = default;

	auto save(const std::string& msg) -> void
	{
		if (!status)
		{
			return;
		}
		MapSharedGuard guard(name);

		fs.open(name, mode);
		if (fs.is_open())
		{
			fs << '\n' << msg << '\n';
		}

		fs.close();
	}

	auto save(const char* msg) -> void
	{
		if (!status)
		{
			return;
		}

		MapSharedGuard guard(name);

		fs.open(name, mode);
		if (fs.is_open())
		{
			fs << '\n' << msg << '\n';
		}

		fs.close();
	}

	auto save(const std::vector<std::string>& vMsg) -> void
	{
		if (!status)
		{
			return;
		}
		MapSharedGuard guard(name);

		fs.open(name, mode);

		for (const auto& i : vMsg)
		{
			fs << '\n' << i << '\n';
		}
		fs.close();
	}

	static auto statusOn() -> void
	{
		status = true;
	}

	static auto statusOff() -> void
	{
		status = false;
	}

	static auto Status() -> bool
	{
		return status;
	}
};

inline bool Saver::status(false);
#endif // !_SAVER_


#ifndef LOADER_
#define LOADER_


class Loader : public BankIOBase
{
public:
	explicit Loader(std::string fileName) : BankIOBase(std::move(fileName))
	{
	}

	Loader(const Loader&) = delete;

	auto operator=(const Loader&) -> void = delete;

	~Loader() override = default;

	auto load() -> std::vector<std::string>
	{
		MapSharedGuard guard(name);
		std::vector<std::string> buffer;
		buffer.reserve(20);
		fs.open(name, std::ios::in);

		if (fs.is_open())
		{
			std::string temp;
			while (fs >> temp)
			{
				buffer.emplace_back(temp);
			}
		}
		fs.close();

		return buffer;
	}

	auto load(std::vector<std::string>& buffer) -> void
	{
		buffer.reserve(20);
		MapSharedGuard guard(name);

		fs.open(name, std::ios::in);
		if (fs.is_open())
		{
			std::string temp;
			while (fs >> temp)
			{
				buffer.emplace_back(temp);
			}
		}
		fs.close();
	}

	auto loadByLine() -> std::vector<std::string>
	{
		std::vector<std::string> buffer;
		buffer.reserve(20);
		MapSharedGuard guard(name);

		fs.open(name, std::ios::in);
		if (fs.is_open())
		{
			std::string temp;
			while (std::getline(fs, temp))
			{
				buffer.emplace_back(temp);
			}
		}

		fs.close();

		return buffer;
	}

	auto loadOneLine() -> std::string
	{
		std::string content;
		MapSharedGuard guard(name);

		fs.open(name, std::ios::in);
		if (fs.is_open())
		{
			std::string temp;
			std::getline(fs, content);
		}

		fs.close();
		return content;
	}
};
#endif // !_LOADER_
