//
//  MPWEchoCommand.h
//  MPWShellScriptKit
//
//  Created by Marcel Weiher on 6/2/07.
//  Copyright 2007 Marcel Weiher. All rights reserved.
//

#import <MPWFoundation/MPWFoundation.h>


@interface MPWEchoCommand : MPWFilter {
	id	toEcho;
}

-pipe:otherCommand;

@end

@interface  MPWWriteStream(wrapped)

-(MPWWriteStream*)wrappedAsMPWStream;
-process;
-adaptCommand:aCommand;
// -pipe:other;

@end
