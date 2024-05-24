#ifndef CONFIG_H
#define CONFIG_H
#include <stdbool.h>
enum CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_ {
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_LAST_USED = 0,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_640X480 = 1,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_1280X720 = 2,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_1280X800 = 3,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_1280X960 = 4,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_1920X1080 = 5,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_2560X1440 = 6,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_2560X1600 = 7,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_2560X1920 = 8,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE_3840X2160 = 9,
	CONFIG_DISPLAY_WINDOW_STARTUP_SIZE__COUNT = 10
};
typedef int CONFIG_DISPLAY_WINDOW_STARTUP_SIZE;

enum CONFIG_DISPLAY_UI_FIT_ {
	CONFIG_DISPLAY_UI_FIT_CENTER = 0,
	CONFIG_DISPLAY_UI_FIT_SCALE = 1,
	CONFIG_DISPLAY_UI_FIT_STRETCH = 2,
	CONFIG_DISPLAY_UI_FIT__COUNT = 3
};
typedef int CONFIG_DISPLAY_UI_FIT;

enum CONFIG_DISPLAY_UI_ASPECT_RATIO_ {
	CONFIG_DISPLAY_UI_ASPECT_RATIO_NATIVE = 0,
	CONFIG_DISPLAY_UI_ASPECT_RATIO_AUTO = 1,
	CONFIG_DISPLAY_UI_ASPECT_RATIO_4X3 = 2,
	CONFIG_DISPLAY_UI_ASPECT_RATIO_16X9 = 3,
	CONFIG_DISPLAY_UI_ASPECT_RATIO__COUNT = 4
};
typedef int CONFIG_DISPLAY_UI_ASPECT_RATIO;

enum CONFIG_NET_BACKEND_ {
	CONFIG_NET_BACKEND_NAT = 0,
	CONFIG_NET_BACKEND_UDP = 1,
	CONFIG_NET_BACKEND_PCAP = 2,
	CONFIG_NET_BACKEND__COUNT = 3
};
typedef int CONFIG_NET_BACKEND;

enum CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL_ {
	CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL_TCP = 0,
	CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL_UDP = 1,
	CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL__COUNT = 2
};
typedef int CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL;

enum CONFIG_SYS_MEM_LIMIT_ {
	CONFIG_SYS_MEM_LIMIT_64 = 0,
	CONFIG_SYS_MEM_LIMIT_128 = 1,
	CONFIG_SYS_MEM_LIMIT__COUNT = 2
};
typedef int CONFIG_SYS_MEM_LIMIT;

enum CONFIG_SYS_AVPACK_ {
	CONFIG_SYS_AVPACK_SCART = 0,
	CONFIG_SYS_AVPACK_HDTV = 1,
	CONFIG_SYS_AVPACK_VGA = 2,
	CONFIG_SYS_AVPACK_RFU = 3,
	CONFIG_SYS_AVPACK_SVIDEO = 4,
	CONFIG_SYS_AVPACK_COMPOSITE = 5,
	CONFIG_SYS_AVPACK_NONE = 6,
	CONFIG_SYS_AVPACK__COUNT = 7
};
typedef int CONFIG_SYS_AVPACK;

struct config {
  struct general {
    bool show_welcome;
    struct updates {
      bool check;
    } updates;
    const char *screenshot_dir;
    bool skip_boot_anim;
    int last_viewed_menu_index;
    const char *user_token;
    struct snapshots {
      struct shortcuts {
        const char *f5;
        const char *f6;
        const char *f7;
        const char *f8;
      } shortcuts;
      bool filter_current_game;
    } snapshots;
  } general;
  struct input {
    struct bindings {
      const char *port1;
      const char *port2;
      const char *port3;
      const char *port4;
    } bindings;
    const char *gamecontrollerdb_path;
    bool auto_bind;
    bool background_input_capture;
    struct keyboard_controller_scancode_map {
      int a;
      int b;
      int x;
      int y;
      int dpad_left;
      int dpad_up;
      int dpad_right;
      int dpad_down;
      int back;
      int start;
      int white;
      int black;
      int lstick_btn;
      int rstick_btn;
      int guide;
      int lstick_up;
      int lstick_left;
      int lstick_right;
      int lstick_down;
      int ltrigger;
      int rstick_up;
      int rstick_left;
      int rstick_right;
      int rstick_down;
      int rtrigger;
    } keyboard_controller_scancode_map;
  } input;
  struct display {
    struct quality {
      int surface_scale;
    } quality;
    struct window {
      bool fullscreen_on_startup;
      bool fullscreen_exclusive;
      CONFIG_DISPLAY_WINDOW_STARTUP_SIZE startup_size;
      int last_width;
      int last_height;
      bool vsync;
    } window;
    struct ui {
      bool show_menubar;
      bool show_notifications;
      bool hide_cursor;
      bool use_animations;
      CONFIG_DISPLAY_UI_FIT fit;
      CONFIG_DISPLAY_UI_ASPECT_RATIO aspect_ratio;
      int scale;
      bool auto_scale;
    } ui;
    struct debug {
      struct video {
        bool transparency;
        float x_pos;
        float y_pos;
        float x_winsize;
        float y_winsize;
        bool advanced_tree_state;
      } video;
    } debug;
  } display;
  struct audio {
    bool use_dsp;
    float volume_limit;
  } audio;
  struct net {
    bool enable;
    CONFIG_NET_BACKEND backend;
    struct pcap {
      const char *netif;
    } pcap;
    struct udp {
      const char *bind_addr;
      const char *remote_addr;
    } udp;
    struct nat {
      struct forward_ports {
        int host;
        int guest;
        CONFIG_NET_NAT_FORWARD_PORTS_PROTOCOL protocol;
      } *forward_ports;
      unsigned int forward_ports_count;
    } nat;
  } net;
  struct sys {
    CONFIG_SYS_MEM_LIMIT mem_limit;
    CONFIG_SYS_AVPACK avpack;
    struct files {
      const char *bootrom_path;
      const char *flashrom_path;
      const char *eeprom_path;
      const char *hdd_path;
      const char *dvd_path;
    } files;
  } sys;
  struct perf {
    bool hard_fpu;
    bool cache_shaders;
  } perf;
};

#endif

#ifdef DEFINE_CONFIG_TREE
CNode config_tree =
 ctab("config", {
  ctab("general", {
   cbool(
    offsetof(struct config, general.show_welcome),
    "show_welcome", true),
   ctab("updates", {
    cbool(
     offsetof(struct config, general.updates.check),
     "check", true)
   }),
   cstring(
    offsetof(struct config, general.screenshot_dir),
    "screenshot_dir", ""),
   cbool(
    offsetof(struct config, general.skip_boot_anim),
    "skip_boot_anim", false),
   cinteger(
    offsetof(struct config, general.last_viewed_menu_index),
    "last_viewed_menu_index", 0),
   cstring(
    offsetof(struct config, general.user_token),
    "user_token", ""),
   ctab("snapshots", {
    ctab("shortcuts", {
     cstring(
      offsetof(struct config, general.snapshots.shortcuts.f5),
      "f5", ""),
     cstring(
      offsetof(struct config, general.snapshots.shortcuts.f6),
      "f6", ""),
     cstring(
      offsetof(struct config, general.snapshots.shortcuts.f7),
      "f7", ""),
     cstring(
      offsetof(struct config, general.snapshots.shortcuts.f8),
      "f8", "")
    }),
    cbool(
     offsetof(struct config, general.snapshots.filter_current_game),
     "filter_current_game", false)
   })
  }),
  ctab("input", {
   ctab("bindings", {
    cstring(
     offsetof(struct config, input.bindings.port1),
     "port1", ""),
    cstring(
     offsetof(struct config, input.bindings.port2),
     "port2", ""),
    cstring(
     offsetof(struct config, input.bindings.port3),
     "port3", ""),
    cstring(
     offsetof(struct config, input.bindings.port4),
     "port4", "")
   }),
   cstring(
    offsetof(struct config, input.gamecontrollerdb_path),
    "gamecontrollerdb_path", ""),
   cbool(
    offsetof(struct config, input.auto_bind),
    "auto_bind", true),
   cbool(
    offsetof(struct config, input.background_input_capture),
    "background_input_capture", false),
   ctab("keyboard_controller_scancode_map", {
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.a),
     "a", 4),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.b),
     "b", 5),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.x),
     "x", 27),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.y),
     "y", 28),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.dpad_left),
     "dpad_left", 80),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.dpad_up),
     "dpad_up", 82),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.dpad_right),
     "dpad_right", 79),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.dpad_down),
     "dpad_down", 81),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.back),
     "back", 42),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.start),
     "start", 40),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.white),
     "white", 30),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.black),
     "black", 31),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.lstick_btn),
     "lstick_btn", 32),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.rstick_btn),
     "rstick_btn", 33),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.guide),
     "guide", 34),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.lstick_up),
     "lstick_up", 8),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.lstick_left),
     "lstick_left", 22),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.lstick_right),
     "lstick_right", 9),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.lstick_down),
     "lstick_down", 7),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.ltrigger),
     "ltrigger", 26),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.rstick_up),
     "rstick_up", 12),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.rstick_left),
     "rstick_left", 13),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.rstick_right),
     "rstick_right", 15),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.rstick_down),
     "rstick_down", 14),
    cinteger(
     offsetof(struct config, input.keyboard_controller_scancode_map.rtrigger),
     "rtrigger", 18)
   })
  }),
  ctab("display", {
   ctab("quality", {
    cinteger(
     offsetof(struct config, display.quality.surface_scale),
     "surface_scale", 1)
   }),
   ctab("window", {
    cbool(
     offsetof(struct config, display.window.fullscreen_on_startup),
     "fullscreen_on_startup", false),
    cbool(
     offsetof(struct config, display.window.fullscreen_exclusive),
     "fullscreen_exclusive", false),
    cenum(
     offsetof(struct config, display.window.startup_size),
     "startup_size", {"last_used", "640x480", "1280x720", "1280x800", "1280x960", "1920x1080", "2560x1440", "2560x1600", "2560x1920", "3840x2160"}, "1280x960"),
    cinteger(
     offsetof(struct config, display.window.last_width),
     "last_width", 640),
    cinteger(
     offsetof(struct config, display.window.last_height),
     "last_height", 480),
    cbool(
     offsetof(struct config, display.window.vsync),
     "vsync", true)
   }),
   ctab("ui", {
    cbool(
     offsetof(struct config, display.ui.show_menubar),
     "show_menubar", true),
    cbool(
     offsetof(struct config, display.ui.show_notifications),
     "show_notifications", true),
    cbool(
     offsetof(struct config, display.ui.hide_cursor),
     "hide_cursor", true),
    cbool(
     offsetof(struct config, display.ui.use_animations),
     "use_animations", true),
    cenum(
     offsetof(struct config, display.ui.fit),
     "fit", {"center", "scale", "stretch"}, "scale"),
    cenum(
     offsetof(struct config, display.ui.aspect_ratio),
     "aspect_ratio", {"native", "auto", "4x3", "16x9"}, "auto"),
    cinteger(
     offsetof(struct config, display.ui.scale),
     "scale", 1),
    cbool(
     offsetof(struct config, display.ui.auto_scale),
     "auto_scale", true)
   }),
   ctab("debug", {
    ctab("video", {
     cbool(
      offsetof(struct config, display.debug.video.transparency),
      "transparency", false),
     cnumber(
      offsetof(struct config, display.debug.video.x_pos),
      "x_pos", 100.0),
     cnumber(
      offsetof(struct config, display.debug.video.y_pos),
      "y_pos", 100.0),
     cnumber(
      offsetof(struct config, display.debug.video.x_winsize),
      "x_winsize", 600.0),
     cnumber(
      offsetof(struct config, display.debug.video.y_winsize),
      "y_winsize", 150.0),
     cbool(
      offsetof(struct config, display.debug.video.advanced_tree_state),
      "advanced_tree_state", false)
    })
   })
  }),
  ctab("audio", {
   cbool(
    offsetof(struct config, audio.use_dsp),
    "use_dsp", false),
   cnumber(
    offsetof(struct config, audio.volume_limit),
    "volume_limit", 1)
  }),
  ctab("net", {
   cbool(
    offsetof(struct config, net.enable),
    "enable", false),
   cenum(
    offsetof(struct config, net.backend),
    "backend", {"nat", "udp", "pcap"}, "nat"),
   ctab("pcap", {
    cstring(
     offsetof(struct config, net.pcap.netif),
     "netif", "")
   }),
   ctab("udp", {
    cstring(
     offsetof(struct config, net.udp.bind_addr),
     "bind_addr", "0.0.0.0:9368"),
    cstring(
     offsetof(struct config, net.udp.remote_addr),
     "remote_addr", "1.2.3.4:9368")
   }),
   ctab("nat", {
    carray(
     offsetof(struct config, net.nat.forward_ports),
     offsetof(struct config, net.nat.forward_ports_count),
     sizeof(struct config::net::nat::forward_ports),
     "forward_ports", 
     ctab("", {
      cinteger(
       offsetof(struct config::net::nat::forward_ports, host),
       "host", 0),
      cinteger(
       offsetof(struct config::net::nat::forward_ports, guest),
       "guest", 0),
      cenum(
       offsetof(struct config::net::nat::forward_ports, protocol),
       "protocol", {"tcp", "udp"}, "tcp")
     })
    )
   })
  }),
  ctab("sys", {
   cenum(
    offsetof(struct config, sys.mem_limit),
    "mem_limit", {"64", "128"}, "64"),
   cenum(
    offsetof(struct config, sys.avpack),
    "avpack", {"scart", "hdtv", "vga", "rfu", "svideo", "composite", "none"}, "hdtv"),
   ctab("files", {
    cstring(
     offsetof(struct config, sys.files.bootrom_path),
     "bootrom_path", ""),
    cstring(
     offsetof(struct config, sys.files.flashrom_path),
     "flashrom_path", ""),
    cstring(
     offsetof(struct config, sys.files.eeprom_path),
     "eeprom_path", ""),
    cstring(
     offsetof(struct config, sys.files.hdd_path),
     "hdd_path", ""),
    cstring(
     offsetof(struct config, sys.files.dvd_path),
     "dvd_path", "")
   })
  }),
  ctab("perf", {
   cbool(
    offsetof(struct config, perf.hard_fpu),
    "hard_fpu", true),
   cbool(
    offsetof(struct config, perf.cache_shaders),
    "cache_shaders", true)
  })
 });

#endif
