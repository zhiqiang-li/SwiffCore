/*
    SwiftFont.h
    Copyright (c) 2011, musictheory.net, LLC.  All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of musictheory.net, LLC nor the names of its contributors
          may be used to endorse or promote products derived from this software
          without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL MUSICTHEORY.NET, LLC BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#import <Foundation/Foundation.h>

@class SwiftMovie;

@interface SwiftFontDefinition : NSObject <SwiftDefinition> {
@private
    SwiftMovie *m_movie;
 
    NSString   *m_name;
    NSString   *m_fullName;
    NSString   *m_copyright;
    UInt16     *m_codeTable;

    CTFontDescriptorRef m_fontDescriptor;

    NSUInteger  m_glyphCount;

    UInt16      m_libraryID;
    BOOL        m_bold;
    BOOL        m_italic;
}


// Font information is distributed among DefineFont/DefineFontInfo/DefineFontName tags.  Hence, the
// -initWithParser:tag:version: pattern used by other classes doesn't fit here.
//
// When encountering one of these tags, the movie should read the fontID from the stream, create or lookup
// the corresponding font, and then call one of the readDefineFont... methods
//
- (id) initWithLibraryID:(UInt16)libraryID movie:(SwiftMovie *)movie;

- (void) readDefineFontTagFromParser:(SwiftParser *)parser;
- (void) readDefineFontNameTagFromParser:(SwiftParser *)parser;
- (void) readDefineFontInfoTagFromParser:(SwiftParser *)parser;
- (void) readDefineFontAlignZonesFromParser:(SwiftParser *)parser;

@property (nonatomic, assign, readonly) UInt16 libraryID;

@property (nonatomic, /*strong*/ readonly) CTFontDescriptorRef fontDescriptor;

@property (nonatomic, retain, readonly) NSString *name;
@property (nonatomic, retain, readonly) NSString *fullName;
@property (nonatomic, retain, readonly) NSString *copyright;

@property (nonatomic, assign, readonly) NSUInteger glyphCount;
@property (nonatomic, assign, readonly) UInt16 *codeTable;

@property (nonatomic, assign, readonly, getter=isBold)   BOOL bold;
@property (nonatomic, assign, readonly, getter=isItalic) BOOL italic;

@end
