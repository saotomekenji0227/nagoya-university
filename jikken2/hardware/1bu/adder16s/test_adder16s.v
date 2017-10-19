/*                                           *
 * test_adder16s.v                           *
 * $B=g=x2sO)HG(B 16$B%S%C%H2C;;2sO)$N%F%9%H%Y%s%A(B *
 *                                           */
 
`timescale 1ns / 1ns    // $B%7%_%e%l!<%7%g%s$NC10L;~4V(B / $B@:EY(B
                                                // 1ns = 1/1000000000 sec
`include "adder16s.v"   // adder16.v $B$N<h$j9~$_(B
 
module test ;
        reg reset, clk, cin;
        reg [15:0] x, y;
 
        wire [15:0] sum;
        wire cout;
 
        adder16s  adder16s(clk, reset, x, y, cin, sum, cout);
 
        always begin
                #5      clk = ~clk;
        end
 
        always begin
                #8      x = x + 100;
                        y = y + 200;
        end
 
        initial begin
 
           reset = 1; clk = 0; x = 0; y = 0; cin = 0 ;
           #20 reset = 0;
           #20 reset = 1;
        end
 
endmodule
