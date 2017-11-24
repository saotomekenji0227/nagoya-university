/********/
/* pc.v */
/********/

//
// �ץ���५���󥿤ν���ͤ� 0x00400000
//

//                +----+
//         clock->|    |
//         reset->|    |
// pc_next[31:0]->|    |->pc[31:0]
//                +----+

module pc (clock, reset, pc_next, pc);  // �����ϥݡ���

  input       clock, reset;   // ���� ����å�, �ꥻ�å�
  input  [31:0]    pc_next;   // ���� 32-bit ����PC�˥��åȤ�����
  output [31:0]         pc;   // ���� 32-bit PC

  reg    [31:0]     pc_reg;   // PC�ѥ쥸����

  // Always �֥�å�: �ץ���५����
  // ����: clock, reset, pc_next
  // ����: pc_reg
  // �쥸����: pc_reg
  always @(posedge clock or negedge reset) begin
    if (reset == 1'b0) begin
	pc_reg <= 32'h00400000;
    end else begin
	pc_reg <= pc_next;
    end
  end

  assign pc = pc_reg;   
endmodule
