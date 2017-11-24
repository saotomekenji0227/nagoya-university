/*******************/
/* ram8x2048_sim.v */
/*******************/

`define   SCAN_ASCII_ADDR  13'h0310
`define   SCAN_ASCII_WEN   1'b1

//                        +----+
//                   clk->|    |
//        ram_addr[12:0]->|    |
//      ram_write_enable->|    |->ram_read_data[31:0]
//  ram_write_data[31:0]->|    |
//    key_ram_addr[12:0]->|    |
//   key_ram_wdata[31:0]->|    |
//           key_ram_wen->|    |
//                        +----+

//
// RAM$B$N5-=R!JO@M}%7%_%e%l!<%7%g%sMQ!K(B
//

module ram8x2048_sim (clk, ram_addr, ram_write_enable,
		      ram_write_data, ram_read_data, key_ram_addr, key_ram_wdata , key_ram_wen);

  // Inputs
  input                       clk;    // $B%/%m%C%/(B
  input  [12:0]          ram_addr;    // 13-bit address, byte
  input          ram_write_enable;    // $B=q$-9~$_(B(1)/$BFI$_(B(0)
  input  [31:0]    ram_write_data;    // 32-bit data
  input  [12:0]     key_ram_addr;    // 13-bit address, byte
  input  [31:0]    key_ram_wdata;    // 32-bit data
  input              key_ram_wen;
   
  // Outputs
  output [31:0]     ram_read_data;    // 32-bit data

  reg    [31:0]         mem[0:2048];  // 32x2048 regs
  reg    [31:0]	        read_data;

  // Wire
  wire    [5:0]         word_addr;    // 6-bit address, word

  assign word_addr = ram_addr[12:2];

  // $B=q$-9~$_(B
  always @(posedge clk) begin
    if (ram_write_enable == 1'b1) begin
      mem[word_addr] <= ram_write_data;
    end
  end

  // $BFI$_(B
  always @(word_addr or ram_write_enable or ram_write_data) begin
    if (ram_write_enable == 1'b0) begin
      read_data = mem[word_addr];
    end else begin
      read_data = ram_write_data;
    end
  end

  assign ram_read_data = ((key_ram_addr == `SCAN_ASCII_ADDR)
                            && (key_ram_wen == `SCAN_ASCII_WEN)
                            && (ram_addr == `SCAN_ASCII_ADDR)
                            && (ram_write_enable == 1'b0)) ? key_ram_wdata : read_data;

endmodule
