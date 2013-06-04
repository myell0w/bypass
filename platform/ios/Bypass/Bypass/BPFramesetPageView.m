//
// Created by Audun Holm Ellertsen on 6/4/13.
// Copyright (c) 2013 Uncodin. All rights reserved.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <QuartzCore/QuartzCore.h>
#import "BPFramesetPageView.h"

@interface NoFadeTiledLayer : CATiledLayer


@end

@implementation NoFadeTiledLayer

+ (CFTimeInterval)fadeDuration
{
  return 0;
}


@end

@implementation BPFramesetPageView
{
  CTFramesetterRef _framesetter;
  CTFrameRef _textFrame;
}

- (id)initWithFrame:(CGRect)frame framesetter:(CTFramesetterRef)framesetter
{
  if (self = [super initWithFrame:frame]) {
    _framesetter = framesetter;
    [self setBackgroundColor:[UIColor whiteColor]];

    CGAffineTransform transform = CGAffineTransformMakeScale(1, -1);
    CGAffineTransformTranslate(transform, 0, -self.bounds.size.height);
    self.transform = transform;

    CGPathRef path = CGPathCreateWithRect(self.frame, NULL);
    _textFrame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0,0), path, NULL);
    CGPathRelease(path);

    CFRetain(_framesetter);
    NoFadeTiledLayer *layer = (NoFadeTiledLayer *) self.layer;
    layer.tileSize = CGSizeMake(1024, 1024);
  }
  return self;
}

- (void)dealloc
{
  CFRelease(_framesetter);
  CFRelease(_textFrame);
}

+(Class) layerClass
{
  return [NoFadeTiledLayer class];
}

- (void)drawRect:(CGRect)rect
{
  CGContextRef context = UIGraphicsGetCurrentContext();
  CGContextSetFillColorWithColor(context, [[self backgroundColor] CGColor]);
  CGContextFillRect(context, rect);

//  CGContextSetStrokeColorWithColor(context, [[UIColor darkGrayColor] CGColor]);
//  CGContextStrokeRect(context, rect);

  CGContextSetStrokeColorWithColor(context, [[UIColor blackColor] CGColor]);
  CTFrameDraw(_textFrame, context);
}


@end
