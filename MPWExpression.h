//
//  MPWExpression.h
//  MPWTalk
//
//  Created by marcel on Mon Jul 02 2001.
//  Copyright (c) 2001 Marcel Weiher. All rights reserved.
//

#import <MPWFoundation/MPWFoundation.h>
#import <ObjectiveSmalltalk/MPWEvaluable.h>

@interface MPWExpression : MPWObject <MPWEvaluable> {
    int offset,len;
}

-variablesRead;
-variablesWritten;

intAccessor_h(offset , setOffset)
intAccessor_h(len, setLen)

@end

@interface NSObject(evaluating)

-(void)addToVariablesRead:(NSMutableSet*)variableList;
-(void)addToVariablesWritten:(NSMutableSet*)variableList;
-evaluateIn:aContext;

@end


@interface NSObject(compiling)

-compileIn:aContext;

@end