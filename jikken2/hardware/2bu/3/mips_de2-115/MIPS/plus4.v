/***********/
/* plus4.v */
/***********/

//              +----+
// inc_a[31:0]->|    |->inc_y[31:0]
//              +----+

module plus4 (inc_a, inc_y);  // �����ϥݡ���
  input  [31:0]  inc_a;          // ���� 32-bit
  output [31:0]  inc_y;          // ���� 32-bit

  assign inc_y = inc_a + 4;
endmodule
