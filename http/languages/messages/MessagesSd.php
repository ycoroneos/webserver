<?php
/** Sindhi (سنڌي)
 *
 * To improve a translation please visit https://translatewiki.net
 *
 * @ingroup Language
 * @file
 *
 * @author Aursani
 */

$fallback8bitEncoding = 'windows-1256';
$rtl = true;

$namespaceNames = array(
	NS_MEDIA            => 'ذريعات',
	NS_SPECIAL          => 'خاص',
	NS_TALK             => 'بحث',
	NS_USER             => 'يوزر',
	NS_USER_TALK        => 'يوزر_بحث',
	NS_PROJECT_TALK     => '$1_بحث',
	NS_FILE             => 'عڪس',
	NS_FILE_TALK        => 'عڪس_بحث',
	NS_MEDIAWIKI        => 'ذريعات_وڪي',
	NS_MEDIAWIKI_TALK   => 'ذريعات_وڪي_بحث',
	NS_TEMPLATE         => 'سانچو',
	NS_TEMPLATE_TALK    => 'سنچو_بحث',
	NS_HELP             => 'مدد',
	NS_HELP_TALK        => 'مدد_بحث',
	NS_CATEGORY         => 'زمرو',
	NS_CATEGORY_TALK    => 'زمرو_بحث',
);

$specialPageAliases = array(
	'Allmessages'               => array( 'سڀ نياپا' ),
	'Allpages'                  => array( 'سڀ صفحا' ),
	'Ancientpages'              => array( 'قديم صفحا' ),
	'Block'                     => array( 'آءِ پي بندش' ),
	'BrokenRedirects'           => array( 'ٽٽل چورڻا' ),
	'Categories'                => array( 'زمرا' ),
	'Confirmemail'              => array( 'برقٽپال تصديقيو' ),
	'Contributions'             => array( 'ڀاڱيداريون' ),
	'CreateAccount'             => array( 'کاتو کوليو' ),
	'DoubleRedirects'           => array( 'ٻٽا چورڻا' ),
	'Emailuser'                 => array( 'برقٽپال يوزر' ),
	'Export'                    => array( 'برآمد' ),
	'FileDuplicateSearch'       => array( 'ساڳيا فائيل ڳولا' ),
	'Filepath'                  => array( 'فائيل ڏس' ),
	'Import'                    => array( 'درآمد' ),
	'Invalidateemail'           => array( 'ناقابلڪار برقٽپال' ),
	'BlockList'                 => array( 'آءِ پي بندش فهرست' ),
	'Listadmins'                => array( 'منتظمين فهرست' ),
	'Listbots'                  => array( 'بوٽس فهرست' ),
	'Listfiles'                 => array( 'عڪس فهرست' ),
	'Listredirects'             => array( 'چورڻا فهرست' ),
	'Listusers'                 => array( 'يوزر فهرست' ),
	'Lockdb'                    => array( 'اعدادخانو بند' ),
	'Log'                       => array( 'لاگس' ),
	'Lonelypages'               => array( 'يتيم صفحا' ),
	'Longpages'                 => array( 'طويل صفحا' ),
	'MergeHistory'              => array( 'سوانح ضماءُ' ),
	'MIMEsearch'                => array( 'مائيم ڳولا' ),
	'Movepage'                  => array( 'صفحو چوريو' ),
	'Mycontributions'           => array( 'منهنجون ڀاڱيداريون' ),
	'Mypage'                    => array( 'منهنجو صفحو' ),
	'Mytalk'                    => array( 'مون سان ڳالهه' ),
	'Newimages'                 => array( 'نوان عڪس' ),
	'Newpages'                  => array( 'نوان صفحا' ),
	'Popularpages'              => array( 'مقبول صفحا' ),
	'Preferences'               => array( 'ترجيحات' ),
	'Prefixindex'               => array( 'اڳياڙي ڏسڻي' ),
	'Protectedpages'            => array( 'تحفظيل صفحا' ),
	'Protectedtitles'           => array( 'تحفظيل عنوان' ),
	'Randompage'                => array( 'بلا ترتيب' ),
	'Randomredirect'            => array( 'بلا ترتيب چورڻو' ),
	'Recentchanges'             => array( 'تازيون تبديليون' ),
	'Search'                    => array( 'ڳولا' ),
	'Shortpages'                => array( 'مختصر صفحا' ),
	'Specialpages'              => array( 'خاص صفحا' ),
	'Statistics'                => array( 'انگ اکر' ),
	'Uncategorizedcategories'   => array( 'اڻ زمرايل زمرا' ),
	'Uncategorizedimages'       => array( 'اڻ زمرايل عڪس' ),
	'Uncategorizedpages'        => array( 'اڻزمرايل صفحا' ),
	'Uncategorizedtemplates'    => array( 'اڻ زمرايل سانچا' ),
	'Undelete'                  => array( 'اڻ ڊاهيو' ),
	'Unlockdb'                  => array( 'اعدادخانو کول' ),
	'Unusedcategories'          => array( 'اڻ استعماليل زمرا' ),
	'Unusedimages'              => array( 'اڻ استعماليل عڪس' ),
	'Unusedtemplates'           => array( 'اڻ استعماليل سانچا' ),
	'Unwatchedpages'            => array( 'اڻٽيٽيل صفحا' ),
	'Upload'                    => array( 'چاڙهيو' ),
	'Userlogin'                 => array( 'يوزر لاگ اِن' ),
	'Userlogout'                => array( 'يوزر لاگ آئوٽ' ),
	'Userrights'                => array( 'يوزر حق' ),
	'Version'                   => array( 'ورزن' ),
	'Wantedcategories'          => array( 'گھربل زمرا' ),
	'Wantedpages'               => array( 'گھربل صفحا' ),
	'Watchlist'                 => array( 'ٽيٽ فهرست' ),
	'Whatlinkshere'             => array( 'هتان ڳنڍيل صفحا' ),
	'Withoutinterwiki'          => array( 'ري بين الوڪي' ),
);

$magicWords = array(
	'redirect'                  => array( '0', '#چوريو', '#REDIRECT' ),
	'localmonth'                => array( '1', 'مقاميمهينو', 'LOCALMONTH', 'LOCALMONTH2' ),
	'localmonthname'            => array( '1', 'مقاميمهينونالو', 'LOCALMONTHNAME' ),
	'localday'                  => array( '1', 'مقاميڏينهن', 'LOCALDAY' ),
	'localday2'                 => array( '1', 'مقاميڏينهن2', 'LOCALDAY2' ),
	'localdayname'              => array( '1', 'مقاميڏينهننالو', 'LOCALDAYNAME' ),
	'localyear'                 => array( '1', 'مقاميسال', 'LOCALYEAR' ),
	'localtime'                 => array( '1', 'مقاميوقت', 'LOCALTIME' ),
	'localhour'                 => array( '1', 'مقاميڪلاڪ', 'LOCALHOUR' ),
	'numberofpages'             => array( '1', 'صفحنجوتعداد', 'NUMBEROFPAGES' ),
	'numberofarticles'          => array( '1', 'مضموننجوتعداد', 'NUMBEROFARTICLES' ),
	'numberoffiles'             => array( '1', 'فائيلنجوتعداد', 'NUMBEROFFILES' ),
	'numberofusers'             => array( '1', 'يوزرسجوتعداد', 'NUMBEROFUSERS' ),
	'numberofedits'             => array( '1', 'ترميمنجوتعداد', 'NUMBEROFEDITS' ),
	'pagename'                  => array( '1', 'صفحيجوعنوان', 'PAGENAME' ),
	'namespace'                 => array( '1', 'نانئپولار', 'NAMESPACE' ),
	'talkspace'                 => array( '1', 'بحثپولار', 'TALKSPACE' ),
	'subjectspace'              => array( '1', 'مضمونپولار', 'SUBJECTSPACE', 'ARTICLESPACE' ),
	'fullpagename'              => array( '1', 'صحفيجوپورونالو', 'FULLPAGENAME' ),
	'msg'                       => array( '0', 'نياپو:', 'MSG:' ),
	'img_right'                 => array( '1', 'ساڄو', 'right' ),
	'img_left'                  => array( '1', 'کاٻو', 'left' ),
	'img_none'                  => array( '1', 'ڪجهنه', 'none' ),
	'img_width'                 => array( '1', '$1 عڪسلون', '$1px' ),
	'img_center'                => array( '1', 'مرڪز', 'center', 'centre' ),
	'img_top'                   => array( '1', 'سِرُ', 'top' ),
	'img_middle'                => array( '1', 'وچ', 'middle' ),
	'img_bottom'                => array( '1', 'تَرُ', 'bottom' ),
	'sitename'                  => array( '1', 'سرزميننالو', 'SITENAME' ),
	'ns'                        => array( '0', 'نپ', 'NS:' ),
	'localurl'                  => array( '0', 'مقامييوآريل', 'LOCALURL:' ),
	'grammar'                   => array( '0', 'وياڪرڻ', 'GRAMMAR:' ),
	'currentweek'               => array( '1', 'هلندڙهفتو', 'CURRENTWEEK' ),
	'currentdow'                => array( '1', 'اڄوڪوڏينهن', 'CURRENTDOW' ),
	'localweek'                 => array( '1', 'مقاميهفتو', 'LOCALWEEK' ),
	'plural'                    => array( '0', 'جمع', 'PLURAL:' ),
	'fullurl'                   => array( '0', 'مڪمليوآريل', 'FULLURL:' ),
	'currenttimestamp'          => array( '1', 'هلندڙوقتمهر', 'CURRENTTIMESTAMP' ),
	'localtimestamp'            => array( '1', 'مقاميوقتمهر', 'LOCALTIMESTAMP' ),
	'directionmark'             => array( '1', 'طرفنشان', 'DIRECTIONMARK', 'DIRMARK' ),
	'language'                  => array( '0', '#ٻولي:', '#LANGUAGE:' ),
	'contentlanguage'           => array( '1', 'موادٻولي', 'CONTENTLANGUAGE', 'CONTENTLANG' ),
	'pagesinnamespace'          => array( '1', 'نپ۾صفحا', 'PAGESINNAMESPACE:', 'PAGESINNS:' ),
	'numberofadmins'            => array( '1', 'منتظمينجوتعداد', 'NUMBEROFADMINS' ),
	'special'                   => array( '0', 'خاص', 'special' ),
	'filepath'                  => array( '0', 'فائيلڏس', 'FILEPATH:' ),
	'hiddencat'                 => array( '1', '__ لڪل زمرو __', '__HIDDENCAT__' ),
	'pagesincategory'           => array( '1', 'زمريجاصفحا', 'PAGESINCATEGORY', 'PAGESINCAT' ),
	'pagesize'                  => array( '1', 'صفحيجيماپ', 'PAGESIZE' ),
);

