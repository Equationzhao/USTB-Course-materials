`timescale 1ns / 1ps

module add32_4(a,b,clk,cin,cout,sum);
input[31:0] a,b;
input clk,cin;
output reg [31:0]sum;
output reg cout;
reg[31:0] temp_a,temp_b;
reg temp_ci;
reg first_rco,second_rco,third_rco;
reg[7:0] first_sum,third_a,third_b;
reg[23:0] first_a,first_b,third_sum;
reg[15:0] second_sum,second_a,second_b;
//输入数据缓存
always@(posedge clk)  
   begin
      temp_a<=a;
      temp_b<=b;
      temp_ci<=cin;
   end
always@(posedge clk)
   begin
   //第一级加（低8位）
      {first_rco,first_sum}<=9'b0+temp_a[7:0]+temp_b[7:0]+temp_ci;
   //未参加计算的数据缓存
       first_a<=temp_a[31:8];             
       first_b<=temp_b[31:8];
   end
always@(posedge clk)
   begin
   //第二级数据加（[15:8]位相加）
      {second_rco,second_sum}<={9'b0+first_a[7:0]+first_b[7:0]+first_rco,first_sum};
   //数据缓存   
       second_a<=first_a[23:8];         
       second_b<=first_b[23:8];
   end
always@(posedge clk)
   begin
   //第三级数据加（[23:15]位相加）
      {third_rco,third_sum}<={9'b0+second_a[7:0]+second_b[7:0]+second_rco,second_sum};
   //数据缓存                                 
       third_a<=second_a[15:8];         
       third_b<=second_b[15:8]; 
   end
always@(posedge clk)
   begin
   //第四级数据加（[31:24]位相加）
      {cout,sum}<={9'b0+third_a[7:0]+third_b[7:0]+third_rco,third_sum};         
   end
endmodule
