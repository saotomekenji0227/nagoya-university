/**************/
/* mux5_5_5.v */
/**************/

//           +----+
//  d0[4:0]->|    |
//  d1[4:0]->|    |->y[4:0]
//        s->|    |
//           +----+

module mux5_5_5 (d0, d1, s, y);  // �����ϥݡ���
  input  [4:0] d0;          // ���� 5-bit d0
  input  [4:0] d1;          // ���� 5-bit d1
  input         s;          // ���� 1-bit  s
  output [4:0]  y;          // ���� 5-bit  y

  // Multiplexer body
  // if (s == 0) y = d0; else y = d1;
  // ���ϥݡ��Ȥ��Ф��������� assign ʸ�ǹԤ�
  assign y = (s == 1'b0) ? d0 : d1;
endmodule