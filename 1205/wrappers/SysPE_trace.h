	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
		if ( SysPE0 != NULL ) {
			esc_trace_signal( &SysPE0->clk, ( std::string(name()) + std::string( ".SysPE.clk" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->rst, ( std::string(name()) + std::string( ".SysPE.rst" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->weight_in.busy, ( std::string(name()) + std::string( ".SysPE.weight_in.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->weight_in.vld, ( std::string(name()) + std::string( ".SysPE.weight_in.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->weight_in.data, ( std::string(name()) + std::string( ".SysPE.weight_in.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->act_in.busy, ( std::string(name()) + std::string( ".SysPE.act_in.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->act_in.vld, ( std::string(name()) + std::string( ".SysPE.act_in.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->act_in.data, ( std::string(name()) + std::string( ".SysPE.act_in.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->accum_in.busy, ( std::string(name()) + std::string( ".SysPE.accum_in.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->accum_in.vld, ( std::string(name()) + std::string( ".SysPE.accum_in.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->accum_in.data, ( std::string(name()) + std::string( ".SysPE.accum_in.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->weight_out.busy, ( std::string(name()) + std::string( ".SysPE.weight_out.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->weight_out.vld, ( std::string(name()) + std::string( ".SysPE.weight_out.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->weight_out.data, ( std::string(name()) + std::string( ".SysPE.weight_out.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->act_out.busy, ( std::string(name()) + std::string( ".SysPE.act_out.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->act_out.vld, ( std::string(name()) + std::string( ".SysPE.act_out.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->act_out.data, ( std::string(name()) + std::string( ".SysPE.act_out.data" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->accum_out.busy, ( std::string(name()) + std::string( ".SysPE.accum_out.busy" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->accum_out.vld, ( std::string(name()) + std::string( ".SysPE.accum_out.vld" ) ).c_str(), esc_trace_vcd );
			esc_trace_signal( &SysPE0->accum_out.data, ( std::string(name()) + std::string( ".SysPE.accum_out.data" ) ).c_str(), esc_trace_vcd );
		}
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		if ( SysPE0 != NULL ) {
			esc_trace_signal( &SysPE0->clk, ( std::string(name()) + std::string( ".SysPE.clk" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->rst, ( std::string(name()) + std::string( ".SysPE.rst" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->weight_in.busy, ( std::string(name()) + std::string( ".SysPE.weight_in.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->weight_in.vld, ( std::string(name()) + std::string( ".SysPE.weight_in.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->weight_in.data, ( std::string(name()) + std::string( ".SysPE.weight_in.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->act_in.busy, ( std::string(name()) + std::string( ".SysPE.act_in.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->act_in.vld, ( std::string(name()) + std::string( ".SysPE.act_in.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->act_in.data, ( std::string(name()) + std::string( ".SysPE.act_in.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->accum_in.busy, ( std::string(name()) + std::string( ".SysPE.accum_in.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->accum_in.vld, ( std::string(name()) + std::string( ".SysPE.accum_in.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->accum_in.data, ( std::string(name()) + std::string( ".SysPE.accum_in.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->weight_out.busy, ( std::string(name()) + std::string( ".SysPE.weight_out.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->weight_out.vld, ( std::string(name()) + std::string( ".SysPE.weight_out.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->weight_out.data, ( std::string(name()) + std::string( ".SysPE.weight_out.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->act_out.busy, ( std::string(name()) + std::string( ".SysPE.act_out.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->act_out.vld, ( std::string(name()) + std::string( ".SysPE.act_out.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->act_out.data, ( std::string(name()) + std::string( ".SysPE.act_out.data" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->accum_out.busy, ( std::string(name()) + std::string( ".SysPE.accum_out.busy" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->accum_out.vld, ( std::string(name()) + std::string( ".SysPE.accum_out.vld" ) ).c_str(), esc_trace_fsdb );
			esc_trace_signal( &SysPE0->accum_out.data, ( std::string(name()) + std::string( ".SysPE.accum_out.data" ) ).c_str(), esc_trace_fsdb );
		}
	}
