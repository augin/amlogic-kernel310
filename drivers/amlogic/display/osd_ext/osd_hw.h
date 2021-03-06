#ifndef OSD_HW_H
#define OSD_HW_H

typedef enum {
	OSD1 = 0,
	OSD2
} osd_ext_index_t;

typedef enum {
	DISABLE = 0,
	ENABLE
} osd_ext_enable_t;

typedef enum {
	SCAN_MODE_INTERLACE,
	SCAN_MODE_PROGRESSIVE
} scan_mode_t;

typedef enum {
	OSD_COLOR_MODE = 0,
	OSD_ENABLE,
	OSD_COLOR_KEY,
	OSD_COLOR_KEY_ENABLE,
	OSD_GBL_ALPHA,
	OSD_CHANGE_ORDER,
	OSD_FREESCALE_COEF,
	DISP_GEOMETRY,
	DISP_SCALE_ENABLE,
	DISP_FREESCALE_ENABLE,
	DISP_OSD_ROTATE,
	HW_REG_INDEX_MAX
} hw_reg_index;

typedef struct {
	s32 x_start;
	s32 x_end;
	s32 y_start;
	s32 y_end;
} pandata_t;

#define OSD_ORDER_01		1	 /*forground osd1*/
#define OSD_ORDER_10		2	 /*forground osd2*/
#define OSD_GLOBAL_ALPHA_DEF  0xff
#define OSD_DATA_BIG_ENDIAN 	0
#define OSD_DATA_LITTLE_ENDIAN 1
#define OSD_TC_ALPHA_ENABLE_DEF 0  //disable tc_alpha
#define REG_OFFSET		0x20

extern void osd_ext_set_colorkey_hw(u32 index, u32 bpp, u32 colorkey);
extern void osd_ext_srckey_enable_hw(u32 index, u8 enable);
extern void osd_ext_set_gbl_alpha_hw(u32 index, u32 gbl_alpha);
extern u32 osd_ext_get_gbl_alpha_hw(u32 index);
extern void osd_ext_setup(struct osd_ctl_s *osd_ext_ctl,
	u32 xoffset,
	u32 yoffset,
	u32 xres,
	u32 yres,
	u32 xres_virtual ,
	u32 yres_virtual,
	u32 disp_start_x,
	u32 disp_start_y,
	u32 disp_end_x,
	u32 disp_end_y,
	u32 fbmem,
	const color_bit_define_t *color,
	int index);
extern void osddev_ext_update_disp_axis_hw(
	u32 display_h_start,
	u32 display_h_end,
	u32 display_v_start,
	u32 display_v_end,
	u32 xoffset,
	u32 yoffset,
	u32 mode_change,
	u32 index) ;
extern void osd_ext_change_osd_ext_order_hw(u32 index, u32 order);
extern u32 osd_ext_get_osd_ext_order_hw(u32 index);
extern void osd_ext_free_scale_enable_hw(u32 index, u32 enable);
extern void osd_ext_get_free_scale_enable_hw(u32 index, u32 * free_scale_enable);
extern void osd_ext_free_scale_width_hw(u32 index, u32 width) ;
extern void osd_ext_get_free_scale_width_hw(u32 index, u32 * free_scale_width);
extern void osd_ext_free_scale_height_hw(u32 index, u32 height);
extern void osd_ext_get_free_scale_height_hw(u32 index, u32 * free_scale_height);
extern void osd_ext_get_free_scale_axis_hw(u32 index, s32 *x0, s32 *y0, s32 *x1, s32 *y1);
extern void osd_ext_set_free_scale_axis_hw(u32 index, s32 x0, s32 y0, s32 x1, s32 y1);
extern void osd_ext_get_scale_axis_hw(u32 index, s32 *x0, s32 *y0, s32 *x1, s32 *y1);
extern void osd_ext_set_scale_axis_hw(u32 index, s32 x0, s32 y0, s32 x1, s32 y1);
extern void osd_ext_get_window_axis_hw(u32 index, s32 *x0, s32 *y0, s32 *x1, s32 *y1);
extern void osd_ext_set_window_axis_hw(u32 index, s32 x0, s32 y0, s32 x1, s32 y1);
extern void osd_ext_get_free_scale_mode_hw(u32 index, u32 *freescale_mode);
extern void osd_ext_free_scale_mode_hw(u32 index,u32 freescale_mode);
extern void osd_ext_get_osd_ext_info_hw(u32 index, s32(*posdval)[4], u32(*posdreq)[5], s32 info_flag);
extern void osd_ext_get_block_windows_hw(u32 index, u32 *windows);
extern void osd_ext_set_block_windows_hw(u32 index, u32 *windows);
extern void osd_ext_get_block_mode_hw(u32 index, u32 *mode);
extern void osd_ext_set_block_mode_hw(u32 index, u32 mode);
extern void osd_ext_enable_3d_mode_hw(int index, int enable);
extern void osd_ext_set_2x_scale_hw(u32 index, u16 h_scale_enable, u16 v_scale_enable);
extern void osd_ext_set_osd_ext_rotate_on_hw(u32 index, u32 on_off);
extern void osd_ext_get_osd_ext_rotate_on_hw(u32 index, u32 *on_off);
extern void osd_ext_set_osd_ext_rotate_angle_hw(u32 index, u32 angle);
extern void osd_ext_get_osd_ext_rotate_angle_hw(u32 index, u32 *angle);
extern void osd_ext_get_prot_canvas_hw(u32 index, s32 *x_start, s32 *y_start, s32 *x_end, s32 *y_end);
extern void osd_ext_set_prot_canvas_hw(u32 index, s32 x_start, s32 y_start, s32 x_end, s32 y_end);
extern void osd_ext_setpal_hw(unsigned regno, unsigned red, unsigned green, unsigned blue, unsigned transp, int index);
extern void osd_ext_enable_hw(int enable, int index);
extern void osd_ext_pan_display_hw(unsigned int xoffset, unsigned int yoffset, int index);
extern int    osd_ext_sync_request(u32 index, u32 yres,u32 xoffset ,u32 yoffset,s32 in_fence_fd);
extern s32  osd_ext_wait_vsync_event(void);
#if defined(CONFIG_FB_OSD2_CURSOR)
extern void osd_ext_cursor_hw(s16 x, s16 y, s16 xstart, s16 ystart, u32 osd_ext_w, u32 osd_ext_h, int index);
#endif
extern void osd_ext_suspend_hw(void);
extern void osd_ext_resume_hw(void);
extern void osd_ext_init_hw(u32  logo_loaded);
extern void osd_ext_get_angle_hw(u32 index, u32 * angle);
extern void osd_ext_set_angle_hw(u32 index, u32 angle);
extern void osd_ext_get_clone_hw(u32 index, u32 *clone);
extern void osd_ext_set_clone_hw(u32 index, u32 clone);
#endif
