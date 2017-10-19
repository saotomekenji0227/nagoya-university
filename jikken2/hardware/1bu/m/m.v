`define st0 2'b00
`define st1 2'b01
`define st2 2'b10
`define st3 2'b11

module m (clk, reset, x, y);
  input clk, reset, x;
  output y;

  reg y_reg;         // 1-bit ���ϥ쥸����
  reg [1:0] st_reg;  // 2-bit ���֥쥸����

  assign y = y_reg;

  always @(posedge clk or negedge reset) begin
    if (reset == 1'b0) begin
      /*** �쥸�����ν�������� ***/
	y_reg = 1'b0;
	st_reg = 2'b00;
    end else begin
      case (st_reg)
        `st0: begin  // ���� 0 �ˤ����
          if (x == 1'b0) begin
	    /*** 0 �����Ϥ��줿���ξ������� ***/
		st_reg = 2'b01; 
          end else begin
	    /*** 1 �����Ϥ��줿���ξ������� ***/
		st_reg = 2'b00;
          end
          /*** �����ͤΥ��å� ***/
           	y_reg = 1'b0;
        end
        `st1: begin  // ���� 1 �ˤ����
          if (x == 1'b0) begin
		st_reg = 2'b10;
          end else begin
		st_reg = 2'b00;
          end
		y_reg = 1'b0;
        end
        `st2: begin  // ���� 2 �ˤ����
          if (x == 1'b0) begin
		st_reg = 2'b10;
          end else begin
		st_reg = 2'b11;
          end
		y_reg = 1'b0;
        end
        `st3: begin  // ���� 3 �ˤ����
          if (x == 1'b0) begin
		st_reg = 2'b00;// ��������
          end else begin
		st_reg = 2'b00;// ��������
          end
		y_reg = 1'b1;// �����ͤΥ��å�
        end
      endcase
    end
  end
endmodule // m
