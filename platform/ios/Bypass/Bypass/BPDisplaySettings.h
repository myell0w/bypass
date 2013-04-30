//
// Created by Audun Holm Ellertsen on 4/30/13.
// Copyright (c) 2013 Uncodin. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

@interface BPDisplaySettings : NSObject

@property(nonatomic) CTFontRef defaultFont;
@property(nonatomic) CTFontRef boldFont;
@property(nonatomic) CTFontRef italicFont;
@property(nonatomic) CTFontRef boldItalicFont;
@property(nonatomic) CTFontRef monospaceFont;
@property(nonatomic) CTFontRef quoteFont;
@property(nonatomic) CTFontRef h1Font;
@property(nonatomic) CTFontRef h2Font;
@property(nonatomic) CTFontRef h3Font;
@property(nonatomic) CTFontRef h4Font;
@property(nonatomic) CTFontRef h5Font;
@property(nonatomic) CTFontRef h6Font;

@property(nonatomic) CGFloat bulletIndentation;
@property(nonatomic) CGFloat codeIndentation;
@property(nonatomic) CGFloat quoteIndentation;
@property(nonatomic) CGFloat lineSpacingSmall;
@property(nonatomic) CGFloat paragraphSpacingLarge;
@property(nonatomic) CGFloat paragraphSpacingSmall;
@property(nonatomic) CGFloat paragraphSpacingNone;

@end