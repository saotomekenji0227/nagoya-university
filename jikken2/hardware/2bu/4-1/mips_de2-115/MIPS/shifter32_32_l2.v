/********************/
/* shifter32_32_l2.v */
/********************/

//             +----+
// sh_a[31:0]->|    |->sh_y[31:0]
//             +----+

module shifter32_32_l2 (sh_a, sh_y);  // �����ϥݡ���
  input  [31:0]  sh_a;          // ���� 32-bit
  output [31:0]  sh_y;          // ���� 32-bit

  //Body
  //2-bit �����ե�
  assign sh_y = {sh_a[29:0], 2'b00};
endmodule
