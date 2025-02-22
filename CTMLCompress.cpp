#include "Main.h"

char* Dictionary[]=
{
"<!DOCTYPE html",
"<a",
"<abbr",
"<address",
"<area",
"<article",
"<aside",
"<audio",
"<b",
"<base",
"<bdi",
"<bdo",
"<blockquote",
"<body",
"<br",
"<button",
"<canvas",
"<caption",
"<cite",
"<code",
"<col",
"<colgroup",
"<datalist",
"<dd",
"<del",
"<details",
"<dfn",
"<dialog",
"<div",
"<dl",
"<dt",
"<em",
"<embed",
"<fieldset",
"<figcaption",
"<figure",
"<footer",
"<form",
"<h1",
"<h2",
"<h3",
"<h4",
"<h5",
"<h6",
"<head",
"<header",
"<hr",
"<html",
"<i",
"<iframe",
"<img",
"<input",
"<ins",
"<kbd",
"<label",
"<legend",
"<li",
"<link",
"<main",
"<map",
"<mark",
"<menu",
"<menuitem",
"<meta",
"<meter",
"<nav",
"<noscript",
"<object",
"<ol",
"<optgroup",
"<option",
"<output",
"<p",
"<param",
"<picture",
"<pre",
"<progress",
"<q",
"<rp",
"<rt",
"<ruby",
"<s",
"<samp",
"<script",
"<section",
"<select",
"<small",
"<source",
"<span",
"<strong",
"<style",
"<sub",
"<summary",
"<sup",
"<table",
"<tbody",
"<td",
"<textarea",
"<tfoot",
"<th",
"<thead",
"<time",
"<title",
"<tr",
"<track",
"<u",
"<ul",
"<var",
"<video",
"<wbr",
"</a>",
"</abbr>",
"</address>",
"</area>",
"</article>",
"</aside>",
"</audio>",
"</b>",
"</base>",
"</bdi>",
"</bdo>",
"</blockquote>",
"</body>",
"</br>",
"</button>",
"</canvas>",
"</caption>",
"</cite>",
"</code>",
"</col>",
"</colgroup>",
"</datalist>",
"</dd>",
"</del>",
"</details>",
"</dfn>",
"</dialog>",
"</div>",
"</dl>",
"</dt>",
"</em>",
"</embed>",
"</fieldset>",
"</figcaption>",
"</figure>",
"</footer>",
"</form>",
"</h1>",
"</h2>",
"</h3>",
"</h4>",
"</h5>",
"</h6>",
"</head>",
"</header>",
"</hr>",
"</html>",
"</i>",
"</iframe>",
"</img>",
"</input>",
"</ins>",
"</kbd>",
"</label>",
"</legend>",
"</li>",
"</link>",
"</main>",
"</map>",
"</mark>",
"</menu>",
"</menuitem>",
"</meta>",
"</meter>",
"</nav>",
"</noscript>",
"</object>",
"</ol>",
"</optgroup>",
"</option>",
"</output>",
"</p>",
"</param>",
"</picture>",
"</pre>",
"</progress>",
"</q>",
"</rp>",
"</rt>",
"</ruby>",
"</s>",
"</samp>",
"</script>",
"</section>",
"</select>",
"</small>",
"</source>",
"</span>",
"</strong>",
"</style>",
"</sub>",
"</summary>",
"</sup>",
"</table>",
"</tbody>",
"</td>",
"</textarea>",
"</tfoot>",
"</th>",
"</thead>",
"</time>",
"</title>",
"</tr>",
"</track>",
"</u>",
"</ul>",
"</var>",
"</video>",
"</wbr>"
"audio/*",
"video/*",
"image/*",
"UTF-8",
"UTF-16",
"ISO-8859-8",
"ANSI",
"ASCII",
"ON",
"OFF",
"true",
"false",
"none",
"inherit",
"normal",
"wider",
"narrower",
"ultra_condensed",
"extra_condensed",
"condensed",
"semi_condensed",
"semi_expanded",
"expanded",
"ultra_expanded",
"inherit",
"italic",
"oblique",
"small_caps",
"bold",
"bolder",
"lighter",
"xx_small",
"x_small",
"small",
"medium",
"large",
"x_large",
"xx_large",
"larger",
"smaller",
"left",
"right",
"center",
"justify",
"underline",
"overline",
"line_through",
"blink",
"capitalize",
"uppercase",
"lowercase",
"scroll",
"fixed",
"transparent",
"top",
"bottom",
"repeat",
"repeat_x",
"repeat_y",
"no_repeat",
"auto",
"medium",
"thin",
"thick",
"dotted",
"dashed",
"solid",
"double",
"groove",
"ridge",
"inset",
"outset",
"disc",
"circle",
"square",
"decimal",
"lower_roman",
"upper_roman",
"lower_alpha",
"upper_alpha",
"upper_latin",
"hebrew",
"armenian",
"georgian",
"cjk_ideograpic",
"hiragana",
"katakana",
"hiragana_iroha",
"katakana_iroh",
"outside",
"inside",
"pre",
"nowrap",
"crosshair",
"default",
"pointer",
"move",
"e_resize",
"ne_resize",
"nw_resize",
"n_resize",
"se_resize",
"sw_resize",
"s_resize",
"w_resize",
"text",
"wait",
"help",
"thin",
"thick",
"dotted",
"dashed",
"solid",
"double",
"groove",
"ridge",
"invert",
"open_quote",
"close_quote",
"no_open_quote",
"no_close_quote",
"ltr",
"trl",
"inline",
"block",
"list_item",
"run_in",
"compact",
"marker",
"table",
"inline_table",
"table_row_group",
"table_header_group",
"table_footer_group",
"table_row",
"table_column_group",
"table_column",
"table_cell",
"table_caption",
"static",
"absolute",
"relative",
"fixed",
"embed",
"bidi_override",
"baseline",
"sub",
"super",
"next_top",
"middle",
"text_bottom",
"collapse",
"separate",
"show",
"hide",
"once",
"always",
"number",
"percentage",
"silent",
"x_soft",
"soft",
"medium",
"loud",
"x_loud",
"spell_out",
"time",
"uri",
"mix",
"repeat",
"angle",
"left_side",
"far_left",
"center_left",
"center_right",
"far_right",
"right_side",
"behind",
"leftwards",
"rightwards",
"below",
"level",
"above",
"higher",
"lower",
"x_slow",
"slow",
"fast",
"x_fast",
"faster",
"slower",
"spell_out",
"specific_voice",
"generic_voice",
"frequency",
"x_low",
"low",
"medium",
"high",
"x_high",
"attr",
"calc",
"linear-gradient",
"radial-gradient",
"repeating-linear-gradient",
"repeating-radial-gradient",
"rect",
"url",
"align-content",
"align-items",
"align-self",
"all",
"animation",
"animation-delay",
"animation-direction",
"animation-duration",
"animation-fill-mode",
"animation-iteration-count",
"animation-name",
"animation-play-state",
"animation-timing-function",
"backface-visibility",
"background",
"background-attachment",
"background-blend-mode",
"background-clip",
"background-color",
"background-image",
"background-origin",
"background-position",
"backgroung-repeat",
"background-size",
"border",
"border-bottom",
"border-bottom-color",
"border-bottom-left-radius",
"border-bottom-right-radius",
"border-bottom-style",
"border-bottom-width",
"border-collapse",
"border-color",
"border-image",
"border-image-outset,"
"border-image-repeat",
"border-image-slice",
"border-image-source",
"border-image-width",
"border-left",
"border-left-color",
"border-left-style",
"border-left-width",
"border-radius",
"border-right",
"border-right-color",
"border-right-style",
"border-right-width",
"border-spacing",
"border-style",
"border-top",
"border-top-color",
"border-top-left-radius",
"border-top-right-radius",
"border-top-style",
"border-top-width",
"border-width",
"bottom",
"box-decoration-break",
"box-shadow",
"box-sizing",
"break-after",
"break-before",
"caption-side",
"caret-color",
"charset",
"clear",
"clip",
"color",
"column-count",
"column-fill",
"column-gap",
"column-rule",
"column-rule-color",
"column-rule-style",
"column-rule-width",
"column-span",
"column-width",
"columns",
"content",
"counter-increment",
"counter-reset",
"cursor",
"direction",
"display",
"empty-cells",
"filter",
"flex",
"flex-basis",
"flex-direction",
"flex-flow",
"flex-grow",
"flex-shrink",
"flex-wrap",
"float",
"font",
"font-face",
"font-family",
"font-feature-settings",
"font-feature-values",
"font-kerning",
"font-language-override",
"font-size",
"font-size-adjust",
"font-stretch",
"font-style",
"font-synthesis",
"font-variant",
"font-variant-alternatives",
"font-variant-caps",
"font-variant-east-asian",
"font-variant-ligatures",
"vont-variant-numeric",
"font-variant-position",
"font-weight",
"grid",
"grid-area",
"grid-auto-columns",
"grid-auto-flow",
"grid-auto-rows",
"grid,column",
"grid-column-end",
"grid-column-gap",
"grid-column-start",
"grid-gap",
"grid-row",
"grid-row-end",
"grid-row-gap",
"grid-row-start",
"grid-template",
"grid-template-areas",
"grid-template-columns",
"grid-template-rows",
"hanging-punctuation",
"height",
"hyphens",
"image-orientation",
"image-rendering",
"image-resolution",
"justify-content",
"keyframes",
"left",
"letter-spacing",
"line-break",
"line-height",
"list-style",
"list-style-image",
"list-style-position",
"list-style-type",
"margin",
"margin-bottom",
"margin-left",
"margin-right",
"margin-top",
"max-height",
"max-width",
"media",
"min-height",
"min-width",
"object-fit",
"object-position",
"opacity",
"order",
"orphans",
"outline",
"outline-color",
"outline-offset",
"outline-style",
"outline-width",
"overflow",
"overflow-wrap",
"overflow-x",
"overflow-y",
"padding",
"padding-bottom",
"padding-left",
"padding-right",
"padding-top",
"page-break-after",
"page-break-before",
"page-break-inside",
"perspective",
"perspective-origin",
"position",
"quotes",
"resize",
"right",
"tab-size",
"table-layout",
"text-align",
"text-align-last",
"text-combine-upright",
"text-decoration",
"text-decoration-color",
"text-decoration-line",
"text-decoration-style",
"text-indent",
"text-justify",
"text-orientation",
"text-overflow",
"text-shadow",
"text-transform",
"text-underline-position",
"top",
"transform",
"transform-origin",
"transform-style",
"transition",
"transition-delay",
"transition-duration",
"transition-property",
"transition-timing-function",
"unicode-bidi",
"user-select",
"vertical-align",
"visibility",
"white-space",
"widows",
"width",
"word-break",
"word-spacing",
"word-wrap",
"writing-mode",
"z-index",
"%",
"px",
"dpi",
"em",
":ACTIVE",
"::AFTER",
"::BEFORE",
":CHECKED",
":DISABLED",
":EMPTY",
":ENABLED",
":FIRST_CHILD",
"::FIRST_LETTER",
"::FIRST_LINE",
":FIRST_OF_TYPE",
":FOCUS",
":HOVER",
":IN_RANGE",
":INVALID",
":LAST_CHILD",
":LAST_OF_TYPE",
":LINK",
":ONLY_OF_TYPE",
":ONLY_CHILD",
":OPTIONAL",
":OUT_OF_RANGE",
":READ_ONLY",
":READ_WRITE",
":REQUIRED",
":ROOT",
"::SELECTION",
":TARGET",
":VALID",
":VISITED",	
":active",
"::after",
"::before",
":checked",
":disabled",
":empty",
":enabled",
":first_child",
"::first_letter",
"::first_line",
":first_of_type",
":focus",
":hover",
":in_range",
":invalid",
":last_child",
":last_of_type",
":link",
":only_of_type",
":only_child",
":optional",
":out_of_range",
":read_only",
":read_write",
":required",
":root",
"::selection",
":target",
":valid",
":visited",
"the",
"of",
"to",
"and",
"a",
"in",
"is",
"it",
"you",
"that",
"he",
"was",
"for",
"on",
"are",
"with",
"as",
"I",
"his",
"they",
"be",
"at",
"one",
"have",
"this",
"from",
"or",
"had",
"by",
"hot",
"word",
"but",
"what",
"some",
"we",
"can",
"out",
"other",
"were",
"all",
"there",
"when",
"up",
"use",
"your",
"how",
"said",
"an",
"each",
"she",
"which",
"do",
"their",
"time",
"if",
"will",
"way",
"about",
"many",
"then",
"them",
"write",
"would",
"like",
"so",
"these",
"her",
"long",
"make",
"thing",
"see",
"him",
"two",
"has",
"look",
"more",
"day",
"could",
"go",
"come",
"did",
"number",
"sound",
"no",
"most",
"people",
"my",
"over",
"know",
"water",
"than",
"call",
"first",
"who",
"may",
"down",
"side",
"been",
"now",
"find",
"any",
"new",
"work",
"part",
"take",
"get",
"place",
"made",
"live",
"where",
"after",
"back",
"little",
"only",
"round",
"man",
"year",
"came",
"show",
"every",
"good",
"me",
"give",
"our",
"under",
"name",
"very",
"through",
"just",
"form",
"sentence",
"great",
"think",
"say",
"help",
"low",
"line",
"differ",
"turn",
"cause",
"much",
"mean",
"before",
"move",
"right",
"boy",
"old",
"too",
"same",
"tell",
"does",
"set",
"three",
"want",
"air",
"well",
"also",
"play",
"small",
"end",
"put",
"home",
"read",
"hand",
"port",
"large",
"spell",
"add",
"even",
"land",
"here",
"must",
"big",
"high",
"such",
"follow",
"act",
"why",
"ask",
"men",
"change",
"went",
"light",
"kind",
"off",
"need",
"house",
"picture",
"try",
"us",
"again",
"animal",
"point",
"mother",
"world",
"near",
"build",
"self",
"earth",
"father",
"head",
"stand",
"own",
"page",
"should",
"country",
"found",
"answer",
"school",
"grow",
"study",
"still",
"learn",
"plant",
"cover",
"food",
"sun",
"four",
"between",
"state",
"keep",
"eye",
"never",
"last",
"let",
"thought",
"city",
"tree",
"cross",
"farm",
"hard",
"start",
"might",
"story",
"saw",
"far",
"sea",
"draw",
"left",
"late",
"run",
"don't",
"while",
"press",
"close",
"night",
"real",
"life",
"few",
"north",
"open",
"seem",
"together",
"next",
"white",
"children",
"begin",
"got",
"walk",
"example",
"ease",
"paper",
"group",
"always",
"music",
"those",
"both",
"mark",
"often",
"letter",
"until",
"mile",
"river",
"car",
"feet",
"care",
"second",
"book",
"carry",
"took",
"science",
"eat",
"room",
"friend",
"began",
"idea",
"fish",
"mountain",
"stop",
"once",
"base",
"hear",
"horse",
"cut",
"sure",
"watch",
"color",
"face",
"wood",
"main",
"enough",
"plain",
"girl",
"usual",
"young",
"ready",
"above",
"ever",
"red",
"list",
"though",
"feel",
"talk",
"bird",
"soon",
"body",
"dog",
"family",
"direct",
"pose",
"leave",
"song",
"measure",
"door",
"product",
"black",
"short",
"numeral",
"class",
"wind",
"question",
"happen",
"complete",
"ship",
"area",
"half",
"rock",
"order",
"fire",
"south",
"problem",
"piece",
"told",
"knew",
"pass",
"since",
"top",
"whole",
"king",
"space",
"heard",
"best",
"hour",
"better",
"true .",
"during",
"hundred",
"five",
"remember",
"step",
"early",
"hold",
"west",
"ground",
"interest",
"reach",
"fast",
"verb",
"sing",
"listen",
"six",
"table",
"travel",
"less",
"morning",
"ten",
"simple",
"several",
"vowel",
"toward",
"war",
"lay",
"against",
"pattern",
"slow",
"center",
"love",
"person",
"money",
"serve",
"appear",
"road",
"map",
"rain",
"rule",
"govern",
"pull",
"cold",
"notice",
"voice",
"unit",
"power",
"town",
"fine",
"certain",
"fly",
"fall",
"lead",
"cry",
"dark",
"machine",
"note",
"wait",
"plan",
"figure",
"star",
"box",
"noun",
"field",
"rest",
"correct",
"able",
"pound",
"done",
"beauty",
"drive",
"stood",
"contain",
"front",
"teach",
"week",
"final",
"gave",
"green",
"oh",
"quick",
"develop",
"ocean",
"warm",
"free",
"minute",
"strong",
"special",
"mind",
"behind",
"clear",
"tail",
"produce",
"fact",
"street",
"inch",
"multiply",
"nothing",
"course",
"stay",
"wheel",
"full",
"force",
"blue",
"object",
"decide",
"surface",
"deep",
"moon",
"island",
"foot",
"system",
"busy",
"test",
"record",
"boat",
"common",
"gold",
"possible",
"plane",
"stead",
"dry",
"wonder",
"laugh",
"thousand",
"ago",
"ran",
"check",
"game",
"shape",
"equate",
"miss",
"brought",
"heat",
"snow",
"tire",
"bring",
"yes",
"distant",
"fill",
"east",
"paint",
"language",
"among",
"grand",
"ball",
"yet",
"wave",
"drop",
"heart",
"am",
"present",
"heavy",
"dance",
"engine",
"position",
"arm",
"wide",
"sail",
"material",
"size",
"vary",
"settle",
"speak",
"weight",
"general",
"ice",
"matter",
"circle",
"pair",
"include",
"divide",
"syllable",
"felt",
"perhaps",
"pick",
"sudden",
"count",
"square",
"reason",
"length",
"represent",
"art",
"subject",
"region",
"energy",
"hunt",
"probable",
"bed",
"brother",
"egg",
"ride",
"cell",
"believe",
"fraction",
"forest",
"sit",
"race",
"window",
"store",
"summer",
"train",
"sleep",
"prove",
"lone",
"leg",
"exercise",
"wall",
"catch",
"mount",
"wish",
"sky",
"board",
"joy",
"winter",
"sat",
"written",
"wild",
"instrument",
"kept",
"glass",
"grass",
"cow",
"job",
"edge",
"sign",
"visit",
"past",
"soft",
"fun",
"bright",
"gas",
"weather",
"month",
"million",
"bear",
"finish",
"happy",
"hope",
"flower",
"clothe",
"strange",
"gone",
"jump",
"baby",
"eight",
"village",
"meet",
"root",
"buy",
"raise",
"solve",
"metal",
"whether",
"push",
"seven",
"paragraph",
"third",
"shall",
"held",
"hair",
"describe",
"cook",
"floor",
"either",
"result",
"burn",
"hill",
"safe",
"cat",
"century",
"consider",
"type",
"law",
"bit",
"coast",
"copy",
"phrase",
"silent",
"tall",
"sand",
"soil",
"roll",
"temperature",
"finger",
"industry",
"value",
"fight",
"lie",
"beat",
"excite",
"natural",
"view",
"sense",
"ear",
"else",
"quite",
"broke",
"case",
"middle",
"kill",
"son",
"lake",
"moment",
"scale",
"loud",
"spring",
"observe",
"child",
"straight",
"consonant",
"nation",
"dictionary",
"milk",
"speed",
"method",
"organ",
"pay",
"age",
"section",
"dress",
"cloud",
"surprise",
"quiet",
"stone",
"tiny",
"climb",
"cool",
"design",
"poor",
"lot",
"experiment",
"bottom",
"key",
"iron",
"single",
"stick",
"flat",
"twenty",
"skin",
"smile",
"crease",
"hole",
"trade",
"melody",
"trip",
"office",
"receive",
"row",
"mouth",
"exact",
"symbol",
"die",
"least",
"trouble",
"shout",
"except",
"wrote",
"seed",
"tone",
"join",
"suggest",
"clean",
"break",
"lady",
"yard",
"rise",
"bad",
"blow",
"oil",
"blood",
"touch",
"grew",
"cent",
"mix",
"team",
"wire",
"cost",
"lost",
"brown",
"wear",
"garden",
"equal",
"sent",
"choose",
"fell",
"fit",
"flow",
"fair",
"bank",
"collect",
"save",
"control",
"decimal",
"gentle",
"woman",
"captain",
"practice",
"separate",
"difficult",
"doctor",
"please",
"protect",
"noon",
"whose",
"locate",
"ring",
"character",
"insect",
"caught",
"period",
"indicate",
"radio",
"spoke",
"atom",
"human",
"history",
"effect",
"electric",
"expect",
"crop",
"modern",
"element",
"hit",
"student",
"corner",
"party",
"supply",
"bone",
"rail",
"imagine",
"provide",
"agree",
"thus",
"capital",
"won't",
"chair",
"danger",
"fruit",
"rich",
"thick",
"soldier",
"process",
"operate",
"guess",
"necessary",
"sharp",
"wing",
"create",
"neighbor",
"wash",
"bat",
"rather",
"crowd",
"corn",
"compare",
"poem",
"string",
"bell",
"depend",
"meat",
"rub",
"tube",
"famous",
"dollar",
"stream",
"fear",
"sight",
"thin",
"triangle",
"planet",
"hurry",
"chief",
"colony",
"clock",
"mine",
"tie",
"enter",
"major",
"fresh",
"search",
"send",
"yellow",
"gun",
"allow",
"print",
"dead",
"spot",
"desert",
"suit",
"current",
"lift",
"rose",
"continue",
"block",
"chart",
"hat",
"sell",
"success",
"company",
"subtract",
"event",
"particular",
"deal",
"swim",
"term",
"opposite",
"wife",
"shoe",
"shoulder",
"spread",
"arrange",
"camp",
"invent",
"cotton",
"born",
"determine",
"quart",
"nine",
"truck",
"noise",
"level",
"chance",
"gather",
"shop",
"stretch",
"throw",
"shine",
"property",
"column",
"molecule",
"select",
"wrong",
"gray",
"repeat",
"require",
"broad",
"prepare",
"salt",
"nose",
"plural",
"anger",
"claim",
"continent",
"oxygen",
"sugar",
"death",
"pretty",
"skill",
"women",
"season",
"solution",
"magnet",
"silver",
"thank",
"branch",
"match",
"suffix",
"especially",
"fig",
"afraid",
"huge",
"sister",
"steel",
"discuss",
"forward",
"similar",
"guide",
"experience",
"score",
"apple",
"bought",
"led",
"pitch",
"coat",
"mass",
"card",
"band",
"rope",
"slip",
"win",
"dream",
"evening",
"condition",
"feed",
"tool",
"]total",
"basic",
"smell",
"valley",
"nor",
"double",
"seat",
"arrive",
"master",
"track",
"parent",
"shore",
"division",
"sheet",
"substance",
"favor",
"connect",
"post",
"spend",
"chord",
"fat",
"glad",
"original",
"share",
"station",
"dad",
"bread",
"charge",
"proper",
"bar",
"offer",
"segment",
"slave",
"duck",
"instant",
"market",
"degree",
"populate",
"chick",
"dear",
"enemy",
"reply",
"drink",
"occur",
"support",
"speech",
"nature",
"range",
"steam",
"motion",
"path",
"liquid",
"log",
"meant",
"quotient",
"teeth",
"shell",
"neck"
};

unsigned short Idx1 = 0, Idx2 = 0;

MAINFRAME_API unsigned short RegDictionary(char* Pos, unsigned short count,char *ent, char* beg)
{
	//Check if the token exists in the default dictionary
	for (unsigned short i = 0; i < 1618; ++i)
	{
		if (appstreq(Pos, Dictionary[i]))
			return i;
	}
	int pos;
	//if((pos = appstrstr(ent,)
	//Else we have to add it to our custom dictionary
	memcpy(ent, Pos, count + 1);
	ent += count;
	return ent - beg;
}

MAINFRAME_API BYTE* Compress(char* B)
{
	char Dict[10240];
	BYTE* b = new BYTE[1024];	//Start with this and increase by pow2
	char* ptr = Dict;
	//char* init = (char*)B;	//Save
	//Control mask is used to determine what kind of token we've got and how to end them.

	//Start and Count indices
	unsigned short Count = 0;
	char* Start = 0;
	unsigned int Size = 0;

	while(*B)
	{
		if (*B == '<' || *B == ' ' || *B == '\t' || *B == '\n')
		{
			Start = B;
			++B;
			while (*B && *B == ' ' || *B == '\t' || *B == '\n')
				++B;	//Skip whitespace till we have another character

			//Start counting characters
			while (*B && *B != ' ' || *B != '\t' || *B != '\n')
				++B;
			Count = (unsigned short)(B - Start);
			//Check if the token exists in the default dictionary
			for (unsigned short i = 0; i < 1618; ++i)
			{
				//if (appstreq(Start, Dictionary[i]))
			}

			//if((int)val > 1617)
			//We start at the beginning of the bytes
			if (Size % 2 == 1)
			{
				

			}
			else
			{


			}
		}
		++B;
	}
	return 0;
}

HypBuffer* Extract(HypBuffer* B)
{


	return 0;
}