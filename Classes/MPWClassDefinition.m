//
//  MPWClassDefinition.m
//  ObjectiveSmalltalk
//
//  Created by Marcel Weiher on 4/12/17.
//
//

#import "MPWClassDefinition.h"
#import "NSObjectScripting.h"
#import "MPWClassMethodStore.h"

@implementation MPWClassDefinition


-(void)addMethodsIn:(MPWClassMethodStore*)store
{
    for ( MPWMethod *method in self.methods) {
        [store installMethod:method];
    }
}

-(id)evaluateIn:(id)aContext
{
    Class theClassToDefine=NSClassFromString(self.name);
    if (!theClassToDefine) {
        Class superclass=NSClassFromString(self.superclassName);
        if ( superclass ) {
            [superclass createSubclassWithName:self.name instanceVariableArray:self.instanceVariableDescriptions];
            theClassToDefine=NSClassFromString(self.name);
        }
    }
    [self addMethodsIn:[aContext classStoreForName:self.name]];
    return theClassToDefine;
}


-(void)dealloc
{
    [_name release];
    [_superclassName release];
    [_instanceVariableDescriptions release];
    [_methods release];
    [super dealloc];
}

@end