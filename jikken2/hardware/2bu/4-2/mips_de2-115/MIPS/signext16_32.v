/******************/
/* signext16_32.v */
/******************/

//            +----+
//  sign_ext->|    |
// a16[15:0]->|    |->y32[31:0]
//            +----+

module signext16_32 (sign_ext, a16, y32);  // �����ϥݡ���
  input      sign_ext;          // ���� 1-bit
  input   [15:0]  a16;          // ���� 16-bit
  output  [31:0]  y32;          // ���� 32-bit

  //Body
  //����ĥ
  assign y32 = (sign_ext == 1'b1) ?
               {a16[15], a16[15], a16[15], a16[15],
                a16[15], a16[15], a16[15], a16[15],
                a16[15], a16[15], a16[15], a16[15],
                a16[15], a16[15], a16[15], a16[15],
                a16[15:0]}
               : {16'h0000, a16[15:0]};
endmodule