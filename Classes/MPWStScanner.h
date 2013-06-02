/* MPWStScanner.h created by marcel on Tue 04-Jul-2000 */

#import <MPWFoundation/MPWFoundation.h>

@interface MPWStScanner : MPWScanner
{
	id	intClass,floatClass,stringClass;
	id	tokens;
	BOOL noNumbers;
}

-nextToken;
-(void)pushBack:aToken;
-(BOOL)atSpace;
boolAccessor_h( noNumbers, setNoNumbers )

@end

@interface NSObject(isLiteral)

-(BOOL)isLiteral;
-(BOOL)isToken;
-(BOOL)isKeyword;
-(BOOL)isBinary;
@end

@interface NSString(tokenizing)

-(BOOL)isScheme;
@end
