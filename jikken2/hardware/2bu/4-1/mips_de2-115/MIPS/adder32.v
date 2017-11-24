/************/
/* adder32.v */
/************/

//              +----+
// add_a[31:0]->|    |
// add_b[31:0]->|    |->add_y[31:0]
//              +----+

module adder32 (add_a, add_b, add_y);  // �����ϥݡ���
  input  [31:0]  add_a;          // ���� 32-bit
  input  [31:0]  add_b;          // ���� 32-bit
  output [31:0]  add_y;          // ���� 32-bit

  assign add_y = add_a + add_b;
endmodule
