//
//  ViewController.m
//  webApp
//
//  Created by Tomer on 24/1/15.
//  Copyright (c) 2015 elasticode. All rights reserved.
//

#import "ViewController.h"
#import <ElastiCode/ElastiCode.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(finishedSync) name:@"ElastiCodeInSync" object:nil];
    _viewWeb.delegate = self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)webViewDidFinishLoad:(UIWebView *)webView
{
    _splashView.hidden = YES;
    [ElastiCode takeSnapShot:@"webURL"];
}

- (void)webView:(UIWebView *)webView
didFailLoadWithError:(NSError *)error
{
    _splashView.hidden = YES;
    [ElastiCode takeSnapShot:@"webURL"];
}

- (void)finishedSync {
    [ElastiCode defineDynamicObject:@"webURL"
                               type:(ElastiCodeDObjType_string)
                       defaultValue:@"http://www.elasticode.com"];
    
    NSString *fullURL = (NSString*)[ElastiCode valueForDynamicObject:@"webURL"];
    NSURL *url = [NSURL URLWithString:fullURL];
    NSURLRequest *requestObj = [NSURLRequest requestWithURL:url];
    [_viewWeb loadRequest:requestObj];
}

@end
