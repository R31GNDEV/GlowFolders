//boooooooobs
#include "GlowFolders.h"

NSUserDefaults *_preferences;
BOOL _enabled;

UIColor* prettyColorsString(NSString* hexString) {
    NSString *daString = [hexString stringByReplacingOccurrencesOfString:@" " withString:@""];
    if (![daString containsString:@"#"]) {
        daString = [@"#" stringByAppendingString:daString];
    }
    unsigned rgbValue = 0;
    NSScanner *scanner = [NSScanner scannerWithString:daString];
    [scanner setScanLocation:1]; // bypass '#' character
    [scanner scanHexInt:&rgbValue];

    NSRange range = [hexString rangeOfString:@":" options:NSBackwardsSearch];
    NSString* alphaString;
    if (range.location != NSNotFound) {
        alphaString = [hexString substringFromIndex:(range.location + 1)];
    } else {
        alphaString = @"1.0"; //no opacity specified - just return 1 :/
    }

    return [UIColor colorWithRed:((rgbValue & 0xFF0000) >> 16)/255.0 green:((rgbValue & 0xFF00) >> 8)/255.0 blue:(rgbValue & 0xFF)/255.0 alpha:[alphaString floatValue]];
}

/*

Hooks below. RGB Hex Decode above.

*/

%hook SBFolderIconImageView

-(NSArray *)subviews {
 id subviews = %orig;
 NSString *realBussyString = [_preferences objectForKey:@"backgroundColor"];
 NSLog(@"[*]Glow Folders Color: %@",realBussyString);
 for (MTMaterialView * origSubview in subviews) {
  if ([origSubview isMemberOfClass:%c(MTMaterialView)]) {
   if (realBussyString) {
    origSubview.backgroundColor = prettyColorsString(realBussyString);
   }
   origSubview.blurEnabled = NO;
  }
 }
 return subviews;
}

-(CALayer *)layer {
  CALayer *origLayer = %orig;
  NSString *glowColorString = [_preferences objectForKey:@"shadowColor"];
  NSLog(@"[*]Glow Folders Shadow: %@",glowColorString);
  if (glowColorString) {
    origLayer.shadowColor = prettyColorsString(glowColorString).CGColor;
  }
  origLayer.shadowOpacity = 1;
  return origLayer;
}

%end
/*
%hook MTMaterialView

%end
*/
/*
Init prefs
*/

%ctor {
	_preferences = [[NSUserDefaults alloc] initWithSuiteName:@"gay.kota.glowfolders"];
	[_preferences registerDefaults:@{
		@"enabled" : @YES,
	}];
	_enabled = [_preferences boolForKey:@"enabled"];
	if(_enabled) {
		NSLog(@"[glowfolders] Enabled");
		%init();
	} else {
		NSLog(@"[glowfolders] Disabled, bye!");
	}
}