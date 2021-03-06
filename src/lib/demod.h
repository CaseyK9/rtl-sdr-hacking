#ifndef	__DEMOD_H__
#define	__DEMOD_H__

struct demod_state;

typedef void mode_demod_cb(struct demod_state *);

struct demod_state
{
	int      exit_flag;
	pthread_t thread;
	int16_t  *lowpassed;
	int      lp_len;
	int16_t  lp_i_hist[10][6];
	int16_t  lp_q_hist[10][6];
	int16_t  *result;
	int16_t  droop_i_hist[9];
	int16_t  droop_q_hist[9];
	int      result_len;
	int      rate_in;
	int      rate_out;
	int      rate_out2;
	int      now_r, now_j;
	int      pre_r, pre_j;
	int      prev_index;
	int      downsample;    /* min 1, max 256 */
	int      post_downsample;
	int      output_scale;
	int      squelch_level, conseq_squelch, squelch_hits, terminate_on_squelch;
	int      downsample_passes;
	int      comp_fir_size;
	int      custom_atan;
	int      deemph, deemph_a;
	int      now_lpr;
	int      prev_lpr_index;
	int      dc_block, dc_avg;
	mode_demod_cb *mode_demod;
	pthread_rwlock_t rw;
	pthread_cond_t ready;
	pthread_mutex_t ready_m;
	struct output_state *output_target;
};

extern	void rotate_90(int16_t *buf, uint32_t len);
extern	void full_demod(struct demod_state *d);
extern	void demod_init(struct demod_state *s, struct output_state *o,
	    int max_buf_length, int sample_rate);
extern	void demod_cleanup(struct demod_state *s);

extern		void demod_set(struct demod_state *fm, mode_demod_cb *cb);

#endif
