library verilog;
use verilog.vl_types.all;
entity bcd2 is
    port(
        clk             : in     vl_logic;
        reset           : in     vl_logic;
        x               : in     vl_logic;
        bcd2_out        : out    vl_logic_vector(7 downto 0)
    );
end bcd2;
