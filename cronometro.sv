module cronometro
(
	input logic clk_clk,
	input logic rst_n,
	input logic switch,
	output logic[20:0] leds
);

	platform plat
	(
		.clck_clk(clk),
		.pio_leds_0_external_connection_export(leds),
		.pio_switch_0_external_connection_export(switch),
		.reset_reset_n(rst_n)
	);

endmodule