//
//  RDExtendedSearch.h
//  PDFViewer
//
//  Created by Emanuele Bortolami on 04/08/14.
//
//

#import <Foundation/Foundation.h>

#import "PDFIOS.h"
#import "RDVGlobal.h"
#import "RDVPage.h"

#define SEARCH_LIST 0

@interface RDSearchResult : NSObject

@property (strong, nonatomic) NSString *stringResult;
@property (nonatomic) int page;

+ (RDSearchResult *)initWithString:(NSString *)stringToShow forPage:(int)page;

@end

@interface RDExtendedSearch : NSObject
{
    PDFPage *m_page;
    PDFDoc *m_doc;
    PDFFinder *m_finder;
    void(^finishBlock)(void);
}

@property (nonatomic) BOOL searching;
@property (nonatomic) BOOL stop;
@property (strong, nonatomic) NSString *searchTxt;
@property (strong, nonatomic) NSMutableArray *searchResults;

+ (RDExtendedSearch *)sharedInstance;

- (BOOL)searchInit:(PDFDoc *)doc;
- (void)searchText:(NSString *)text inDoc:(PDFDoc *)doc progress:(void (^)(NSMutableArray *occurrences))progress finish:(void (^)())finish;
- (void)addPageSearchResults:(PDFFinder *)finder forPage:(int)page progress:(void (^)(NSMutableArray *occurrences))progress;
- (BOOL)pageIsInSearchResults:(int)page;
- (int)getNextPageFromCurrentPage:(int)page;
- (int)getPrevPageFromCurrentPage:(int)page;
- (void)clearSearch;
- (void)clearSearch:(void (^)())finish;

- (BOOL)occurrenceAlreadyExist:(RDSearchResult *)searchResult;

- (BOOL)hasPrevOccurrences:(int)curPage;
- (BOOL)hasNextOccurrences:(int)curPage;

@end
