/* See LICENSE file for copyright and license details. */

/* custom definitions */

#define COLORS "/home/love/.cache/wal/colors-wal-dwm.h"

/* appearance */
static       int smartgaps          = 0;
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 4;
static const unsigned int gappiv    = 4;
static const unsigned int gappoh    = 6;
static const unsigned int gappov    = 8;
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "UbuntuMono-R:size=11" };
static const char dmenufont[]       = "monospace:size=10";

/* set this to truncate long window titles */
static const unsigned int trunclength = 96;

/* custom color definitions */
/* #include COLORS */

#ifndef COLORS_WAL_DWM
static const char color1[]       = "#222222";
static const char color2[]       = "#444444";
static const char color3[]       = "#bbbbbb";
static const char color4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
#endif

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { color3, color1, color2 },
	[SchemeSel]  = { color4, col_cyan,  col_cyan  },
	[SchemeStatus] = { color4, "#191919", color2 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	/* { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 }, */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1

#include "layouts.h"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};


/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", color1, "-nf", color3, "-sb", col_cyan, "-sf", color4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include "X11/XF86keysym.h"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,                            XK_Super_L,      spawn,         		{.v = dmenucmd } },
	{ Mod4Mask,			XK_p,		    spawn,			SHCMD("passmenu") },
	{ MODKEY,                       XK_Return, spawn,         			{.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,     			{0} },
	{ MODKEY,                       XK_j,      focusstack,    			{.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,    			{.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,    			{.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,    			{.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,      			{.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,      			{.f = +0.05} },
	{ MODKEY,                       XK_plus,   zoom,          			{0} },
	{ MODKEY,                       XK_Tab,    view,          			{0} },
	{ MODKEY,                       XK_q,      killclient,    			{0} },
	{ MODKEY,                       XK_t,      setlayout,     			{.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,     			{.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,     			{.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,     			{0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,			{0} },
	{ MODKEY,                       XK_0,      view,          			{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,           			{.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,      			{.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,      			{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,        			{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,        			{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q,      quit,          			{0} },
	{ MODKEY,                       XK_x,                   spawn,          SHCMD("dunstctl close") },
	{ MODKEY,                       XK_i,                   spawn,          SHCMD("dunstctl action") },
	{ 0,                            XF86XK_AudioPlay,       spawn,  SHCMD("playpause") },
	{ 0,                            XF86XK_AudioPrev,       spawn,  SHCMD("playpause previous") },
	{ 0,                            XF86XK_AudioNext,       spawn,  SHCMD("playpause next") },
	{ 0,                            XK_Print,               spawn,  SHCMD("maim -s | xclip -selection clipboard -t image/png") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

