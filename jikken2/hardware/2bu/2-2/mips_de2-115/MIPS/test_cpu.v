/*                    *
 * test_cpu.v         *
 * cpu.v �Υƥ��ȥ٥�� *
 *                    */

`timescale 1ns / 1ns    // ���ߥ�졼������ñ�̻��� / ����
                        // 1 ns = 1/1000000000 sec
`include "cpu.v"        // cpu.v �μ�����

module test_cpu ;           // �ƥ��ȥ٥���⥸�塼��, �����ϥݡ���̵��
   // cpu �������� flip-flop(1-bit �쥸����) �����
   reg clk;    // flip-flop
   reg reset;  // flip-flop
   reg clk_ctrl0;
   reg clk_ctrl1;
   reg clk_ctrl_clk;
   reg [12:0] i_ram_addr;   // RAM address
   reg [31:0] i_ram_wdata;  // RAM write data
   reg        i_ram_wen;    // RAM write enable

   // cpu �ν����� wire(������) �����
   wire o_clock;         // 1-bit ������
   wire [7:0] o_pc;      // 8-bit ������
   wire [31:0] o_alu_y;  // 32-bit ������
   wire [31:0]     o_alu_a;    // ALU in a
   wire [31:0]     o_alu_b;    // ALU in b
   wire [3:0]   o_alu_ctrl;    // ALU ctrl
   wire [1:0]   o_alu_comp;    // ALU comp
   wire [31:0] o_reg_data1;    // �쥸���� out data1
   wire [4:0]   o_reg_idx1;    // �쥸���� read idx1
   wire [31:0] o_reg_data2;    // �쥸���� out data2
   wire [4:0]   o_reg_idx2;    // �쥸���� read idx2
   wire [31:0] o_reg_wdata;    // �쥸���� write data
   wire [4:0]   o_reg_widx;    // �쥸���� write idx
   wire          o_reg_wen;    // �쥸���� write enable
   wire [12:0]  o_ram_addr;    // RAM address
   wire [31:0] o_ram_rdata;    // RAM read data
   wire [31:0] o_ram_wdata;    // RAM write data
   wire          o_ram_wen;    // RAM write enable

   // module cpu �μ��β�
   cpu cpua (clk, reset,
            clk_ctrl0, clk_ctrl1, clk_ctrl_clk,
            o_clock, o_pc, o_alu_y, o_alu_a, o_alu_b, o_alu_ctrl, o_alu_comp,
            o_reg_data1, o_reg_idx1, o_reg_data2, o_reg_idx2, o_reg_wdata,
            o_reg_widx, o_reg_wen,
            o_ram_addr, o_ram_rdata, o_ram_wdata, o_ram_wen,
            i_ram_addr, i_ram_wdata, i_ram_wen
            );

   
   // ���ߥ�졼�����ѥ���
   initial begin
       // clk, reset �ν����
       clk = 0; reset = 1;

       clk_ctrl0 = 1; clk_ctrl1 = 1;
       clk_ctrl_clk = 0;

       // 20 ñ�̻���(20 ns)��
       #20  reset = 0;

       // ���� 20 ñ�̻���(20 ns)��
       #20  reset = 1;

       #100000 $finish;
   end

   always begin
     #10 clk = ! clk;
   end

   always begin
     #10 clk_ctrl_clk = ! clk_ctrl_clk;
   end

endmodule
