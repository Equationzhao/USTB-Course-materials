`timescale 1ns / 1ps

module add32_tb();
    reg [31:0] ina;
    reg [31:0] inb;
    reg clk;
    reg cin;
    wire cout;
    wire [31:0] sum;
    initial begin
        ina = 4'bxxxx;
        inb = 4'bxxxx;
        cin = 1'bx;
        clk = 0;
    end
    always #100 clk = ~clk;
    always@(posedge clk)begin
        ina={$random}%2**30;
        inb={$random}%2**30;
        cin={$random}%2;
        #150; 
        cin=1'bx;
    end
   add32_4 a(ina,inb,clk,cin,cout,sum);
endmodule