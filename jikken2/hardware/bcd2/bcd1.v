module bcd1 (clk, reset, x, bcd1_out);
  input clk, reset, x;
  output [3:0] bcd1_out;

  reg [3:0] count_reg;    // 4-bit

  assign bcd1_out = count_reg;

  always @(posedge clk or negedge reset) begin
    if (reset == 1'b0) begin
       count_reg = 4'b0000;
    end else begin
      if (x == 1'b1) begin
        if (count_reg == 4'b1001) begin
	   count_reg = 4'b0000;
        end else begin
	   count_reg = count_reg + 4'b0001;
        end
      end
    end
  end
endmodule // bcd1
