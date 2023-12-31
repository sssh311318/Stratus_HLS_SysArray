	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( SysArray0 != NULL ) {
			esc_trace_signal( &SysArray0->clk, ( std::string(name()) + std::string( ".SysArray.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->rst, ( std::string(name()) + std::string( ".SysArray.rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[0].busy, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(0).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[0].vld, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(0).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[0].data, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(0).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[1].busy, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(1).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[1].vld, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(1).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[1].data, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(1).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[2].busy, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(2).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[2].vld, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(2).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_in_vec[2].data, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(2).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[0].busy, ( std::string(name()) + std::string( ".SysArray.act_in_vec(0).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[0].vld, ( std::string(name()) + std::string( ".SysArray.act_in_vec(0).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[0].data, ( std::string(name()) + std::string( ".SysArray.act_in_vec(0).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[1].busy, ( std::string(name()) + std::string( ".SysArray.act_in_vec(1).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[1].vld, ( std::string(name()) + std::string( ".SysArray.act_in_vec(1).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[1].data, ( std::string(name()) + std::string( ".SysArray.act_in_vec(1).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[2].busy, ( std::string(name()) + std::string( ".SysArray.act_in_vec(2).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[2].vld, ( std::string(name()) + std::string( ".SysArray.act_in_vec(2).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_in_vec[2].data, ( std::string(name()) + std::string( ".SysArray.act_in_vec(2).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[0].busy, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(0).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[0].vld, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(0).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[0].data, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(0).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[1].busy, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(1).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[1].vld, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(1).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[1].data, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(1).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[2].busy, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(2).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[2].vld, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(2).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_out_vec[2].data, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(2).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[0].busy, ( std::string(name()) + std::string( ".SysArray.weight_inter(0).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[0].vld, ( std::string(name()) + std::string( ".SysArray.weight_inter(0).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[0].data, ( std::string(name()) + std::string( ".SysArray.weight_inter(0).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[1].busy, ( std::string(name()) + std::string( ".SysArray.weight_inter(1).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[1].vld, ( std::string(name()) + std::string( ".SysArray.weight_inter(1).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[1].data, ( std::string(name()) + std::string( ".SysArray.weight_inter(1).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[2].busy, ( std::string(name()) + std::string( ".SysArray.weight_inter(2).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[2].vld, ( std::string(name()) + std::string( ".SysArray.weight_inter(2).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->weight_inter[2].data, ( std::string(name()) + std::string( ".SysArray.weight_inter(2).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[0].busy, ( std::string(name()) + std::string( ".SysArray.act_inter(0).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[0].vld, ( std::string(name()) + std::string( ".SysArray.act_inter(0).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[0].data, ( std::string(name()) + std::string( ".SysArray.act_inter(0).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[1].busy, ( std::string(name()) + std::string( ".SysArray.act_inter(1).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[1].vld, ( std::string(name()) + std::string( ".SysArray.act_inter(1).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[1].data, ( std::string(name()) + std::string( ".SysArray.act_inter(1).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[2].busy, ( std::string(name()) + std::string( ".SysArray.act_inter(2).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[2].vld, ( std::string(name()) + std::string( ".SysArray.act_inter(2).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->act_inter[2].data, ( std::string(name()) + std::string( ".SysArray.act_inter(2).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[0].busy, ( std::string(name()) + std::string( ".SysArray.accum_inter(0).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[0].vld, ( std::string(name()) + std::string( ".SysArray.accum_inter(0).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[0].data, ( std::string(name()) + std::string( ".SysArray.accum_inter(0).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[1].busy, ( std::string(name()) + std::string( ".SysArray.accum_inter(1).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[1].vld, ( std::string(name()) + std::string( ".SysArray.accum_inter(1).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[1].data, ( std::string(name()) + std::string( ".SysArray.accum_inter(1).data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[2].busy, ( std::string(name()) + std::string( ".SysArray.accum_inter(2).busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[2].vld, ( std::string(name()) + std::string( ".SysArray.accum_inter(2).vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysArray0->accum_inter[2].data, ( std::string(name()) + std::string( ".SysArray.accum_inter(2).data" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( SysArray0 != NULL ) {
			esc_trace_signal( &SysArray0->clk, ( std::string(name()) + std::string( ".SysArray.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->rst, ( std::string(name()) + std::string( ".SysArray.rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[0].busy, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(0).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[0].vld, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(0).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[0].data, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(0).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[1].busy, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(1).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[1].vld, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(1).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[1].data, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(1).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[2].busy, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(2).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[2].vld, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(2).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_in_vec[2].data, ( std::string(name()) + std::string( ".SysArray.weight_in_vec(2).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[0].busy, ( std::string(name()) + std::string( ".SysArray.act_in_vec(0).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[0].vld, ( std::string(name()) + std::string( ".SysArray.act_in_vec(0).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[0].data, ( std::string(name()) + std::string( ".SysArray.act_in_vec(0).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[1].busy, ( std::string(name()) + std::string( ".SysArray.act_in_vec(1).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[1].vld, ( std::string(name()) + std::string( ".SysArray.act_in_vec(1).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[1].data, ( std::string(name()) + std::string( ".SysArray.act_in_vec(1).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[2].busy, ( std::string(name()) + std::string( ".SysArray.act_in_vec(2).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[2].vld, ( std::string(name()) + std::string( ".SysArray.act_in_vec(2).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_in_vec[2].data, ( std::string(name()) + std::string( ".SysArray.act_in_vec(2).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[0].busy, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(0).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[0].vld, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(0).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[0].data, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(0).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[1].busy, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(1).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[1].vld, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(1).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[1].data, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(1).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[2].busy, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(2).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[2].vld, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(2).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_out_vec[2].data, ( std::string(name()) + std::string( ".SysArray.accum_out_vec(2).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[0].busy, ( std::string(name()) + std::string( ".SysArray.weight_inter(0).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[0].vld, ( std::string(name()) + std::string( ".SysArray.weight_inter(0).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[0].data, ( std::string(name()) + std::string( ".SysArray.weight_inter(0).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[1].busy, ( std::string(name()) + std::string( ".SysArray.weight_inter(1).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[1].vld, ( std::string(name()) + std::string( ".SysArray.weight_inter(1).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[1].data, ( std::string(name()) + std::string( ".SysArray.weight_inter(1).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[2].busy, ( std::string(name()) + std::string( ".SysArray.weight_inter(2).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[2].vld, ( std::string(name()) + std::string( ".SysArray.weight_inter(2).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->weight_inter[2].data, ( std::string(name()) + std::string( ".SysArray.weight_inter(2).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[0].busy, ( std::string(name()) + std::string( ".SysArray.act_inter(0).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[0].vld, ( std::string(name()) + std::string( ".SysArray.act_inter(0).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[0].data, ( std::string(name()) + std::string( ".SysArray.act_inter(0).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[1].busy, ( std::string(name()) + std::string( ".SysArray.act_inter(1).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[1].vld, ( std::string(name()) + std::string( ".SysArray.act_inter(1).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[1].data, ( std::string(name()) + std::string( ".SysArray.act_inter(1).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[2].busy, ( std::string(name()) + std::string( ".SysArray.act_inter(2).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[2].vld, ( std::string(name()) + std::string( ".SysArray.act_inter(2).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->act_inter[2].data, ( std::string(name()) + std::string( ".SysArray.act_inter(2).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[0].busy, ( std::string(name()) + std::string( ".SysArray.accum_inter(0).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[0].vld, ( std::string(name()) + std::string( ".SysArray.accum_inter(0).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[0].data, ( std::string(name()) + std::string( ".SysArray.accum_inter(0).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[1].busy, ( std::string(name()) + std::string( ".SysArray.accum_inter(1).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[1].vld, ( std::string(name()) + std::string( ".SysArray.accum_inter(1).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[1].data, ( std::string(name()) + std::string( ".SysArray.accum_inter(1).data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[2].busy, ( std::string(name()) + std::string( ".SysArray.accum_inter(2).busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[2].vld, ( std::string(name()) + std::string( ".SysArray.accum_inter(2).vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysArray0->accum_inter[2].data, ( std::string(name()) + std::string( ".SysArray.accum_inter(2).data" ) ).c_str(), esc_trace_fsdb );
		}
	}
