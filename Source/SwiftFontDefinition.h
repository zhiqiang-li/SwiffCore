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

enum {
    SwiftFontLanguageCodeNoLanguage = 0,
    SwiftFontLanguageCodeLatin = 1,
    SwiftFontLanguageCodeJapanese = 2,
    SwiftFontLanguageCodeKorean = 3,
    SwiftFontLanguageCodeSimplifiedChinese = 4,
    SwiftFontLanguageCodeTraditionalChinese = 5
};
typedef NSInteger SwiftFontLanguageCode;

@interface SwiftFontDefinition : NSObject {
@private
    UInt16     m_libraryID;
 
    NSString  *m_name;
    NSString  *m_fullName;
    NSString  *m_copyright;

    UInt16    *codeTable;

    NSInteger  m_languageCode;
    NSInteger  m_glyphCount;

    CGFloat    m_ascenderHeight;
    CGFloat    m_descenderHeight;
    CGFloat    m_leadingHeight;

#if 0
    SInt16    *advanceTable;
    SWFRect   *boundsTable;
    SWFShape **glyph;
#endif
    
    BOOL       m_bold;
    BOOL       m_italic;
    BOOL       m_pixelAligned;
    BOOL       m_smallText;
    BOOL       m_hasLayout;
}


// Font information is distributed among DefineFont/DefineFontInfo/DefineFontName tags.  Hence, the
// -initWithParser:tag:version: pattern used by other classes doesn't fit here.
//
// When encountering one of these tags, the movie should read the fontID from the stream, create or lookup
// the corresponding font, and then call one of the readDefineFont... methods
//
- (id) initWithLibraryID:(UInt16)libraryID;

- (void) readDefineFontTagFromParser:(SwiftParser *)parser version:(NSInteger)version;
- (void) readDefineFontNameTagFromParser:(SwiftParser *)parser version:(NSInteger)version;
- (void) readDefineFontInfoTagFromParser:(SwiftParser *)parser version:(NSInteger)version;


@property (nonatomic, assign, readonly) UInt16 libraryID;

@property (nonatomic, assign, readonly) SwiftFontLanguageCode languageCode;

@property (nonatomic, retain, readonly) NSString *name;
@property (nonatomic, retain, readonly) NSString *fullName;
@property (nonatomic, retain, readonly) NSString *copyright;

@property (nonatomic, assign, readonly) CGFloat ascenderHeight;
@property (nonatomic, assign, readonly) CGFloat descenderHeight;
@property (nonatomic, assign, readonly) CGFloat leadingHeight;

@property (nonatomic, assign, readonly, getter=isBold)   BOOL bold;
@property (nonatomic, assign, readonly, getter=isItalic) BOOL italic;

@property (nonatomic, readonly, assign, getter=isPixelAligned) BOOL pixelAligned;

@property (nonatomic, assign, readonly) BOOL hasLayoutInformation;


@end