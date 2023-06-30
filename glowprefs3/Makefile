TARGET := iphone:clang:14.5:12.0
THEOS_PACKAGE_SCHEME = rootless

include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = glowprefs3

glowprefs3_FILES = GLOWRootListController.m
glowprefs3_FRAMEWORKS = UIKit
glowprefs3_PRIVATE_FRAMEWORKS = Preferences
glowprefs3_INSTALL_PATH = /Library/PreferenceBundles
glowprefs3_CFLAGS = -fobjc-arc
glowprefs3_LIBRARIES = colorpicker
#glowprefs_EXTRA_FRAMEWORKS = Cephei CepheiPrefs Alderis

include $(THEOS_MAKE_PATH)/bundle.mk
