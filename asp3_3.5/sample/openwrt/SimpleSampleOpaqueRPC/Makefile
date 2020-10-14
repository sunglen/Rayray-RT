#
# Copyright (C) 2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=SimpleSampleOpaqueRPC
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/SimpleSampleOpaqueRPC
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libpthread
  TITLE:=Simple Sample of OpaqueRPC
  MAINTAINER:=Glen Sun <sunge@126.com>
endef

define Package/SimpleSampleOpaqueRPC/description
  Simple Sample of OpaqueRPC.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

TARGET_CFLAGS += -std=gnu99 -fPIC -g  -D \"Inline=static inline\" -Dpthread_yield=sched_yield
TARGET_LDFLAGS += -lpthread

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) tecs\
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS) -Wall" \
		LDFLAGS="$(TARGET_LDFLAGS)"
	$(MAKE) -C $(PKG_BUILD_DIR)/rSample \
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS) -Wall" \
		LDFLAGS="$(TARGET_LDFLAGS)"
	$(MAKE) -C $(PKG_BUILD_DIR)/rSimple \
		CC="$(TARGET_CC)" \
		CFLAGS="$(TARGET_CFLAGS) -Wall" \
		LDFLAGS="$(TARGET_LDFLAGS)"
endef

define Package/SimpleSampleOpaqueRPC/install
	$(INSTALL_DIR) $(1)/usr/rr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rSimple/SimpleSample-rSimple.exe $(1)/usr/rr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/rSample/SimpleSample-rSample.exe $(1)/usr/rr/bin/
endef

$(eval $(call BuildPackage,SimpleSampleOpaqueRPC))
