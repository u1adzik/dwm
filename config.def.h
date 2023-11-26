/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "SFMono Nerd Font Mono:size=11:antialias=true:autohint=true", "AppleColorEmoji:pixelsize=11:antialias=true:autohint=true" };
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#839496", "#002b36", "#002b36" },
	[SchemeSel]  = { "#839496", "#073642", "#073642" },
};

/* tagging */
static const char *tags[] = { "adzin", "dva", "try", "čatyry", "piać" };


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "TelegramDesktop",    NULL,       NULL,                    1 << 2,      0,           -1 },
	{ "firefox",          NULL,       "Picture-in-Picture",    0,           1,           -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          SHCMD("dmenu_run") },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          SHCMD("st") },
	{ MODKEY,                       XK_w,      spawn,          SHCMD("firefox") },
	{ 0,                            0x1008FF11,spawn,          SHCMD("amixer set Master -q 10%-") },
	{ 0,                            0x1008FF12,spawn,          SHCMD("amixer set Master -q toggle") },
	{ 0,                            0x1008FF13,spawn,          SHCMD("amixer set Master -q 10%+") },
	{ 0,                            0x1008FF02,spawn,          SHCMD("brightnessctl s 5%+") },
	{ 0,                            0x1008FF03,spawn,          SHCMD("brightnessctl s 5%-") },
	{ 0,                            XK_Print,  spawn,          SHCMD("maim -u | xclip -selection clipboard -t image/png") },
	{ 0|ShiftMask,                  XK_Print,  spawn,          SHCMD("maim -su | xclip -selection clipboard -t image/png") },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

