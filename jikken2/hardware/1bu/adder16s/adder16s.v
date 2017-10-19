/*                             *
 * adder16s.v                  *
 * ½ç½ø²óÏ©ÈÇ 16¥Ó¥Ã¥È²Ã»»²óÏ© *
 *                             */

module adder16s (clk, reset, x, y, cin, sum, cout);
	input [15:0] x, y;
	input clk, reset, cin;
	output [15:0] sum;
	output cout;

	reg [15:0] r0, r1;

	assign {cout, sum} = r0 + r1 + cin;

	always @(posedge clk or negedge reset) begin
		if (reset == 1'b0) begin
			r0 <= 0;
			r1 <= 0;
		end else begin
			r0 <= x;
	        r1 <= y;
		end
	end
endmodule
