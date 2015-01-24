//
//  ElastiCode.h
//  ElastiCode
//
//  Created by Dan Iosub on 10/15/13.
//  Copyright (c) 2013 elasticode. All rights reserved.
//

#import <Foundation/Foundation.h>


//Local notifications
#define ELASTICODE_SESSION_STARTED @"ELASTICODE_SESSION_INITIALIZE_SUCCESS"
#define ELASTICODE_SESSION_RESTARTED @"ELASTICODE_SESSION_RESTARTED_SUCCESS"


enum logLevel
{
    elastiCodeLogLevelNone,
    elastiCodeLogLevelErrors,
    elastiCodeLogLevelDetailed
};

typedef enum dObjType
{
    ElastiCodeDObjType_none = 0,
    ElastiCodeDObjType_bool = 1,
    ElastiCodeDObjType_int = 2,
    ElastiCodeDObjType_double = 3,
    ElastiCodeDObjType_string = 4,
    ElastiCodeDObjType_arrayOfBool = 11,
    ElastiCodeDObjType_arrayOfInt = 12,
    ElastiCodeDObjType_arrayOfDouble = 13,
    ElastiCodeDObjType_arrayOfString = 14
} ElastiCodeDObjType;

@interface ElastiCode : NSObject



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Init
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *  This method serves as the entry point to ElastiCode. It must be
 *  called in the scope of applicationDidFinishLaunching.
 *
 * @code
 *  - (void)applicationDidFinishLaunching:(UIApplication *)application
 {
 //ElastiCode startup method
 [ElastiCode startSession:@"YOUR_ELASTICODE_API_KEY"];
 // ....
 }
 * @endcode
 *
 * @param elastiCodeApiKey The API key for this project.
 */
+(void)startSession:(NSString*)elastiCodeApiKey;




/**
 *  Set the connection timeout for the ElastiCode SDK.
 *  Default value is 20 seconds, in case of slow internet connection.
 *  You can change to any positive number.
 *
 *  @param timeout The new timeout in seconds
 */
+(void)setConnectionTimeout:(NSUInteger) timeout;

/**
 *  When you want to force restart the session,
 *  you can call this method to perform a session restart.
 */
+ (void)restartSession;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Share User Info
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *  Update the SDK with info about the user. Please visit the ElastiCode documentation for more info about supported values in this hashmap.
 *
 *  @param userInfo    Provide the server with more about the user. This info will take into consider when choosing the best state for this case.
 */
+(void)shareUserInfo:(NSDictionary*)userInfo;








/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Define Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 *  Define a case and the number of possible states.
 *
 *  @param caseName    The case name
 *  @param numOfStates Number of states for this case.
 *  @param multipleVisits Indicate if this case can become visible more than once
 *
 */
+(void)defineCase:(NSString*)caseName withNumOfStates:(int)numOfStates;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Define Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 *  Define a dynamic object.
 *
 *  @param dObjName The dynamic object name.
 *  @param dObjType The dynamic object type.
 *  @param defaultValue default value that will be used in case of error.
 *
 */
+(void)defineDynamicObject:(NSString*)dObjName type:(ElastiCodeDObjType) dObjType defaultValue:(NSObject*) defaultValue;






/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - State Index For Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Get the selected state index of a case.
 *
 *  @param caseName    The case name
 *
 *  @return The selected state index. 0 for default.
 */
+(int)stateIndexForCase:(NSString*)caseName;


/**
 *  Get the selected state index of a case.
 *
 *  In case you going to use the state index later, use this method, 
 *  and when using index call the visitCase method.
 *
 *  @param caseName    The case name
 *
 *  @return The selected state index. 0 for default.
 */
+(int)stateIndexWithoutVisitForCase:(NSString*)caseName;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - State Index For Case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Get the selected value of a dynamic object.
 *
 *  @param dObjName    The dynamic object name
 *
 *  @return NSObject with the selected value, 
 *  nil in case of using before defining a dynamic object or default value in case of error.
 */
+(NSObject*)valueForDynamicObject:(NSString*)dObjName;


/**
 *  Get the selected value of a dynamic object.
 *
 *  In case you going to use the value later, use this method,
 *  and when using the value, call the visitDynamicObject method.
 *
 *  @param dObjName    The dynamic object name
 *
 *  @return NSObject with the selected value,
 *  nil in case of using before defining a dynamic object or default value in case of error.
 */
+(NSObject*)valueWithoutVisitForDynamicObject:(NSString*)dObjName;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Visit case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Signal the SDK when a case becomes visible to the user.
 *
 *  @param caseName    The case name
 */
+(void)visitCase:(NSString*)caseName;





///**
// *  Signal the SDK when a case becomes visible to the user.
// *
// *  @param caseName    The case name
// *  @param visitInfo    Provide the server with more info to consider when choosing the best state for this case. Please visit the ElastiCode iOS documentation for more info about supported values in this array.
// */
//+(void)visitCase:(NSString*)caseName withInfo:(NSArray*)visitInfo;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Visit case
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Signal the SDK when a dynamic object becomes visible to the user.
 *
 *  @param dObjName    The dynamic object name
 */
+(void)visitDynamicObject:(NSString*)dObjName;


/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Event
/////////////////////////////////////////////////////////////////////////////////////////////////////////




/**
 *  Signal the SDK on events, other then cases.
 *
 *  @param eventName    The event name
 */
+(void)event:(NSString*)eventName;

/**
 *  Signal the SDK on events, other then cases.
 *  With attributes relevant to the event
 *  @param eventName The event name
 *  @param attributes The attributes relevant to the event
 */
 +(void)event:(NSString*)eventName attributes:(NSDictionary*) attributes;




/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Goal Reached
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 *  Indicate when the goal of the case is reached.
 *
 *  @param caseName The case name
 */
+(void)goalReached:(NSString*)caseName;

/**
 *  Indicate when the goal for the dynamic object is reached.
 *
 *  @param dObjName The dynamic object name
 */
+(void)dynamicObjectGoalReached:(NSString*)dObjName;











/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Logging
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/**
 *  Set the log level of the ElastiCode SDK.
 Logs can show errors only (default): elastiCodeLogLevelErrors,
 or detailed log: elastiCodeLogLevelDetailed.
 *
 *  @param logLevel The log level: elastiCodeLogLevelErrors, elastiCodeLogLevelDetailed.
 */
+(void)setLogLevel:(enum logLevel)logLevel;



/////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Debugging
/////////////////////////////////////////////////////////////////////////////////////////////////////////


+(void)activateDebugMode __deprecated_msg("Use devModeWithLogging: method instead");

/**
 *  Activate SDK in debug mode.
 *  SDK analytics will be ignored, and the SDK will get all draft segments
 */
+(void)devModeWithLogging:(enum logLevel) logLevel;

/**
 *  Take case/dynamic object snapshot.
 *  Only available in debug mode, take a screen shot of the visible screen and upload it to MC.
 *  Case must be visited first with 'stateIndexForCase' or 'visitCase'
 *  Dynamic object must be visited first with 'valueForDynamicObject' or 'visitDynamicObject'
 */
+(void)takeSnapShot:(NSString*) caseName;


@end
