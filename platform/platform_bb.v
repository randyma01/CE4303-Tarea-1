
module platform (
	clk_clk,
	reset_reset_n,
	pio_segundos_0_external_connection_export,
	pio_switch_0_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[20:0]	pio_segundos_0_external_connection_export;
	input	[2:0]	pio_switch_0_external_connection_export;
endmodule
