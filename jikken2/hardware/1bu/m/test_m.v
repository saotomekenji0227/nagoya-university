/*                          *
 * test_mv.v                *
 * ���󸡽д�Υƥ��ȥ٥��     *
 *                          */
 
`timescale 1ns / 1ns    // ���ߥ�졼������ñ�̻��� / ����
                                                // 1ns = 1/1000000000 sec
`include "m.v"   // m.v ���ɤ߹���
 
module test ;
  /*** m �������ͳ�Ǽ�ѤΥ쥸���� ****/
  reg reset, clk, x;

  /*** y �ν��ϴ�¬�Ѥο����� ****/
  wire y;

  /*** m �μ��β� ***/
   m ma(clk, reset, x, y);
 
  always begin
    #5      clk = ~clk;
  end
 
  initial begin
    reset = 1; clk = 0; x = 0;

    // 20 ñ�̻���(20 ns)��
    #20 reset = 0;

    // ���� 20 ñ�̻���(20 ns)��
    #20 reset = 1;

    #1  x = 1;
    #10 x = 0;
    #10 x = 0;
    #10 x = 1;
    #10 x = 1;
    #10 x = 1;
    #10 x = 0;

    // ���� 1000 ñ�̻���(1000 ns)��, ��λ
    #1000 $finish;
  end
 
endmodule // test
