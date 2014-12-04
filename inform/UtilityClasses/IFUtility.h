//
//  IFUtility.h
//  Inform
//
//  Created by Toby Nelson, 2014
//

#import <Cocoa/Cocoa.h>

@interface IFUtility : NSObject {
}

// String
+ (bool) safeString:(NSString*) string1 insensitivelyEqualsSafeString:(NSString*) string2;

// URLs
+ (bool) url:(NSURL*) url1 equals:(NSURL*) url2;

// Localization
+ (NSString*) localizedString:(NSString*) key;
+ (NSString*) localizedString: (NSString*) key
                      default: (NSString*) value;
+ (NSString*) localizedString: (NSString*) key
                      default: (NSString*) value
                        table: (NSString*) table;

// Convenience methods for alerts
+ (void) runAlertInformationWindow: (NSWindow*) window
                             title: (NSString*) title
                           message: (NSString*) formatString, ...;
+ (void) runAlertWarningWindow: (NSWindow*) window
                         title: (NSString*) title
                       message: (NSString*) formatString, ...;

+ (void) runAlertWindow: (NSWindow*) window
              localized: (BOOL) alreadyLocalized
                warning: (BOOL) warningStyle
                  title: (NSString*) title
                message: (NSString*) formatString, ...;

+ (void) runAlertYesNoWindow: (NSWindow*) window
                       title: (NSString*) title
                         yes: (NSString*) yes
                          no: (NSString*) no
               modalDelegate: (id) modalDelegate
              didEndSelector: (SEL) alertDidEndSelector
                 contextInfo: (void *) contextInfo
                     message: (NSString*) formatString, ...;

// Sandboxing
+ (BOOL) isSandboxed;

// Paths to common resources
+ (NSURL*) publicLibraryURL;

+ (NSString*) informSupportPath: (NSString *)firstString, ... NS_REQUIRES_NIL_TERMINATION;

// External directories within Application Support or Sandboxed container
+ (NSString*) pathForInformExternalAppSupport;
+ (NSString*) pathForInformExternalExtensions;
+ (NSString*) pathForInformExternalLibraries;
+ (NSString*) pathForInformExternalDocumentation;

// Internal directories within the bundle resources
+ (NSString*) pathForInformInternalAppSupport;          // Path to the internal Inform 7 app support
+ (NSString*) pathForInformInternalExtensions;          // Path to the internal Inform 7 extensions
+ (NSString*) pathForInformInternalLibraries;           // Path to the internal Inform 7 libraries
+ (NSString*) pathForInformInternalDocumentation;       // Path to the internal Inform 7 documentation

@end
