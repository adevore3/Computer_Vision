// generated by Fast Light User Interface Designer (fluid) version 1.0104

#include "PsmUI.h"
#include <FL/Fl_File_Chooser.h>
#include "PsmMain.h"

inline void PsmUI::cb_Open_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Open Images...","*.txt",0);
if (filename)
  theApp->loadSources(filename);
}
void PsmUI::cb_Open(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Open_i(o,v);
}

inline void PsmUI::cb_Open1_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Open Lighting Directions...","*.txt",0);
if (filename)
  theApp->loadLightDirs(filename);
}
void PsmUI::cb_Open1(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Open1_i(o,v);
}

inline void PsmUI::cb_Open2_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Open Normals...","*.dat",0);
if (filename)
  theApp->loadNormals(filename);
}
void PsmUI::cb_Open2(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Open2_i(o,v);
}

inline void PsmUI::cb_Open3_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Open Albedo Map...","*.tga",0);
if (filename)
  theApp->loadAlbedos(filename);
}
void PsmUI::cb_Open3(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Open3_i(o,v);
}

inline void PsmUI::cb_Open4_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Open Depth Map...", "*.dat",0);
if (filename)
  theApp->loadDepths(filename);
}
void PsmUI::cb_Open4(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Open4_i(o,v);
}

inline void PsmUI::cb_saveLights_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Save Lighting Directions...", "*.txt", 0);
if (filename)
  theApp->saveLightDirs(filename);
}
void PsmUI::cb_saveLights(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_saveLights_i(o,v);
}

inline void PsmUI::cb_saveNormals_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Save Normals...","*.dat", 0);
if (filename)
  theApp->saveNormals(filename);
}
void PsmUI::cb_saveNormals(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_saveNormals_i(o,v);
}

inline void PsmUI::cb_saveAlbedos_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Save Albedo Map...","*.tga", 0);
if (filename)
  theApp->saveAlbedos(filename);
}
void PsmUI::cb_saveAlbedos(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_saveAlbedos_i(o,v);
}

inline void PsmUI::cb_saveDepths_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Save Depth Map...","*.dat", 0);
if (filename)
  theApp->saveDepths(filename);
}
void PsmUI::cb_saveDepths(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_saveDepths_i(o,v);
}

inline void PsmUI::cb_Save_i(Fl_Menu_*, void*) {
  char *filename = fl_file_chooser("Save Snapshot...","*.tga", 0);
if (filename)
  view->saveSnapshot(filename);
}
void PsmUI::cb_Save(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Save_i(o,v);
}

inline void PsmUI::cb_Quit_i(Fl_Menu_*, void*) {
  theApp->quit(0);
}
void PsmUI::cb_Quit(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

inline void PsmUI::cb_solveLights_i(Fl_Menu_*, void*) {
  theApp->computeLightDirs();
}
void PsmUI::cb_solveLights(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_solveLights_i(o,v);
}

inline void PsmUI::cb_solveNormals_i(Fl_Menu_*, void*) {
  theApp->computeNormals();
}
void PsmUI::cb_solveNormals(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_solveNormals_i(o,v);
}

inline void PsmUI::cb_solveAlbedos_i(Fl_Menu_*, void*) {
  theApp->computeAlbedos();
}
void PsmUI::cb_solveAlbedos(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_solveAlbedos_i(o,v);
}

inline void PsmUI::cb_solveDepths_i(Fl_Menu_*, void*) {
  theApp->computeDepths();
}
void PsmUI::cb_solveDepths(Fl_Menu_* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_solveDepths_i(o,v);
}

Fl_Menu_Item PsmUI::menu_[] = {
 {"File", 0,  0, 0, 64, 0, 0, 14, 56},
 {"Open Images...", 0,  (Fl_Callback*)PsmUI::cb_Open, 0, 0, 0, 0, 14, 56},
 {"Open Lighting Directions...", 0,  (Fl_Callback*)PsmUI::cb_Open1, 0, 0, 0, 0, 14, 56},
 {"Open Normals...", 0,  (Fl_Callback*)PsmUI::cb_Open2, 0, 0, 0, 0, 14, 56},
 {"Open Albedo Map...", 0,  (Fl_Callback*)PsmUI::cb_Open3, 0, 0, 0, 0, 14, 56},
 {"Open Depths...", 0,  (Fl_Callback*)PsmUI::cb_Open4, 0, 128, 0, 0, 14, 56},
 {"Save Lighting Directions...", 0,  (Fl_Callback*)PsmUI::cb_saveLights, 0, 1, 0, 0, 14, 56},
 {"Save Normals...", 0,  (Fl_Callback*)PsmUI::cb_saveNormals, 0, 1, 0, 0, 14, 56},
 {"Save Albedo Map...", 0,  (Fl_Callback*)PsmUI::cb_saveAlbedos, 0, 1, 0, 0, 14, 56},
 {"Save Depths...", 0,  (Fl_Callback*)PsmUI::cb_saveDepths, 0, 1, 0, 0, 14, 56},
 {"Save VRML...", 0,  0, 0, 129, 0, 0, 14, 56},
 {"Save Snapshot...", 0,  (Fl_Callback*)PsmUI::cb_Save, 0, 128, 0, 0, 14, 56},
 {"Quit", 0,  (Fl_Callback*)PsmUI::cb_Quit, 0, 0, 0, 0, 14, 56},
 {0},
 {"Solve", 0,  0, 0, 64, 0, 0, 14, 56},
 {"Lighting Directions", 0,  (Fl_Callback*)PsmUI::cb_solveLights, 0, 1, 0, 0, 14, 56},
 {"Normals", 0,  (Fl_Callback*)PsmUI::cb_solveNormals, 0, 1, 0, 0, 14, 56},
 {"Albedo Map", 0,  (Fl_Callback*)PsmUI::cb_solveAlbedos, 0, 1, 0, 0, 14, 56},
 {"Depths", 0,  (Fl_Callback*)PsmUI::cb_solveDepths, 0, 1, 0, 0, 14, 56},
 {0},
 {0}
};
Fl_Menu_Item* PsmUI::saveLights = PsmUI::menu_ + 6;
Fl_Menu_Item* PsmUI::saveNormals = PsmUI::menu_ + 7;
Fl_Menu_Item* PsmUI::saveAlbedos = PsmUI::menu_ + 8;
Fl_Menu_Item* PsmUI::saveDepths = PsmUI::menu_ + 9;
Fl_Menu_Item* PsmUI::saveVRML = PsmUI::menu_ + 10;
Fl_Menu_Item* PsmUI::solveLights = PsmUI::menu_ + 15;
Fl_Menu_Item* PsmUI::solveNormals = PsmUI::menu_ + 16;
Fl_Menu_Item* PsmUI::solveAlbedos = PsmUI::menu_ + 17;
Fl_Menu_Item* PsmUI::solveDepths = PsmUI::menu_ + 18;

inline void PsmUI::cb_tabs_i(Fl_Tabs*, void*) {
  tabs->value()->do_callback();
}
void PsmUI::cb_tabs(Fl_Tabs* o, void* v) {
  ((PsmUI*)(o->parent()->user_data()))->cb_tabs_i(o,v);
}

inline void PsmUI::cb_sourcesTab_i(Fl_Group*, void*) {
  view->setMode(PsmView::SOURCES);
}
void PsmUI::cb_sourcesTab(Fl_Group* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->user_data()))->cb_sourcesTab_i(o,v);
}

inline void PsmUI::cb_imageNum_i(Fl_Counter*, void*) {
  view->updateBuffer();
}
void PsmUI::cb_imageNum(Fl_Counter* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->parent()->user_data()))->cb_imageNum_i(o,v);
}

inline void PsmUI::cb_showMask_i(Fl_Check_Button*, void*) {
  view->updateBuffer();
}
void PsmUI::cb_showMask(Fl_Check_Button* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->parent()->user_data()))->cb_showMask_i(o,v);
}

inline void PsmUI::cb_normalsTab_i(Fl_Group*, void*) {
  normalsMode->do_callback();
}
void PsmUI::cb_normalsTab(Fl_Group* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->user_data()))->cb_normalsTab_i(o,v);
}

inline void PsmUI::cb_normalsMode_i(Fl_Choice*, void*) {
  if (normalsMode->value() == 0)
{
  needleSpacing->deactivate();
  view->setMode(PsmView::NORMALS);
} else {
  needleSpacing->activate();
  view->setMode(PsmView::NEEDLES);
};
}
void PsmUI::cb_normalsMode(Fl_Choice* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->parent()->user_data()))->cb_normalsMode_i(o,v);
}

Fl_Menu_Item PsmUI::menu_normalsMode[] = {
 {"RGB", 0,  0, 0, 0, 0, 0, 14, 56},
 {"Needle Map", 0,  0, 0, 0, 0, 0, 14, 56},
 {0}
};

inline void PsmUI::cb_needleSpacing_i(Fl_Counter*, void*) {
  view->redraw();
}
void PsmUI::cb_needleSpacing(Fl_Counter* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->parent()->user_data()))->cb_needleSpacing_i(o,v);
}

#include <FL/Fl_Pixmap.H>
static const char *idata_key[] = {
"35 35 255 2",
"   c gray50",
".  c #15398C",
"X  c #193DA6",
"o  c #39158C",
"O  c #3D19A6",
"+  c #27279C",
"@  c #2B2BAE",
"#  c #2D2DB3",
"$  c #2C3AC4",
"%  c #3A2CC4",
"&  c #3A3AD3",
"*  c #3636CA",
"=  c #0C4C95",
"-  c #1455B6",
";  c #134EAD",
":  c #03779B",
">  c #03658D",
",  c #0A77B2",
"<  c #0E67B6",
"1  c #2045BD",
"2  c #195BC2",
"3  c #1679C6",
"4  c #1965C7",
"5  c #2748C9",
"6  c #2057CA",
"7  c #2B57D6",
"8  c #364AD9",
"9  c #3B55E2",
"0  c #2765D8",
"q  c #2477D7",
"w  c #2062CF",
"e  c #2F77E1",
"r  c #3977E9",
"t  c #3766E5",
"y  c #4C0C95",
"u  c #5514B6",
"i  c #4E13AD",
"p  c #4520BD",
"a  c #77039B",
"s  c #65038D",
"d  c #770AB2",
"f  c #670EB6",
"g  c #5B19C2",
"h  c #4827C9",
"j  c #5720CA",
"k  c #572BD6",
"l  c #4A36D9",
"z  c #553BE2",
"x  c #7916C6",
"c  c #6519C7",
"v  c #6527D8",
"b  c #7724D7",
"n  c #6220CF",
"m  c #772FE1",
"M  c #7739E9",
"N  c #6637E5",
"B  c #4848E4",
"V  c #4857EA",
"C  c #5748EA",
"Z  c #5858F2",
"A  c #5353EF",
"S  c #4979F2",
"D  c #5777F7",
"F  c #4E66F1",
"G  c #7949F2",
"H  c #7757F7",
"J  c #664EF1",
"K  c #6577FB",
"L  c #7765FB",
"P  c #7777FD",
"I  c #6565F9",
"U  c #039194",
"Y  c #0D92B4",
"T  c #0CB295",
"R  c #14A8B6",
"E  c #13B0AD",
"W  c #20B9BD",
"Q  c #178FC7",
"!  c #19A3C2",
"~  c #248AD7",
"^  c #2798D8",
"/  c #209CCF",
"(  c #2F8AE1",
")  c #398AE9",
"_  c #3797E5",
"`  c #20A7CA",
"\'  c #2BA7D6",
"]  c #27B5C9",
"[  c #36B3D9",
"{  c #3BA8E2",
"}  c #15C48C",
"|  c #19C1A6",
" . c #27D69C",
".. c #24CBAC",
"X. c #27C8B7",
"o. c #36DAB1",
"O. c #39E88C",
"+. c #3DE5A6",
"@. c #2CC3C4",
"#. c #38CCC7",
"$. c #3AC3D3",
"%. c #3DD6C1",
"&. c #4F91F3",
"*. c #48A7EA",
"=. c #48B5E4",
"-. c #58A5F2",
";. c #57B5EA",
":. c #53ABEF",
">. c #658AFB",
",. c #778AFD",
"<. c #7798FB",
"1. c #6598F9",
"2. c #77A7F7",
"3. c #79B4F2",
"4. c #66AFF1",
"5. c #45DEBD",
"6. c #4CF195",
"7. c #55E9B6",
"8. c #4EEAAD",
"9. c #77FB9B",
"0. c #65FB8D",
"q. c #77F4B2",
"w. c #67EFB6",
"e. c #48C8D8",
"r. c #55CCDB",
"t. c #4FD8CB",
"y. c #58C3E3",
"u. c #4CC1E0",
"i. c #5BE5C2",
"p. c #77DAD7",
"a. c #64D7D6",
"s. c #66C6E5",
"d. c #77C8E6",
"f. c #79E7C6",
"g. c #65E5C7",
"h. c #910394",
"j. c #920DB4",
"k. c #B20C95",
"l. c #A814B6",
"z. c #B013AD",
"x. c #B920BD",
"c. c #8F17C7",
"v. c #8A24D7",
"b. c #9827D8",
"n. c #9C20CF",
"m. c #8A2FE1",
"M. c #8A39E9",
"N. c #9737E5",
"B. c #A319C2",
"V. c #A720CA",
"C. c #A72BD6",
"Z. c #B527C9",
"A. c #B336D9",
"S. c #A83BE2",
"D. c #914FF3",
"F. c #8A65FB",
"G. c #8A77FD",
"H. c #9877FB",
"J. c #9865F9",
"K. c #A748EA",
"L. c #A558F2",
"P. c #B548E4",
"I. c #B557EA",
"U. c #AB53EF",
"Y. c #A777F7",
"T. c #B479F2",
"R. c #AF66F1",
"E. c #C4158C",
"W. c #C119A6",
"Q. c #D6279C",
"!. c #CB24AC",
"~. c #C827B7",
"^. c #DA36B1",
"/. c #E8398C",
"(. c #E53DA6",
"). c #C32CC4",
"_. c #CC38C7",
"`. c #C33AD3",
"\'. c #D63DC1",
"]. c #DE45BD",
"[. c #F14C95",
"{. c #E955B6",
"}. c #EA4EAD",
"|. c #FB779B",
" X c #FB658D",
".X c #F477B2",
"XX c #EF67B6",
"oX c #C848D8",
"OX c #CC55DB",
"+X c #D84FCB",
"@X c #C358E3",
"#X c #C14CE0",
"$X c #DA77D7",
"%X c #D764D6",
"&X c #C666E5",
"*X c #C877E6",
"=X c #E55BC2",
"-X c #E779C6",
";X c #E565C7",
":X c #8A8AFD",
">X c #8A98FB",
",X c #988AFB",
"<X c #9898F9",
"1X c #88B4F2",
"2X c #93ACF3",
"3X c #B488F2",
"4X c #AC93F3",
"5X c #A5A5F2",
"6X c #A7B5EA",
"7X c #B5A7EA",
"8X c #B5B5E4",
"9X c #ABABEF",
"0X c #91FB94",
"qX c #92F0B4",
"wX c #B9DEBD",
"eX c #B2F195",
"rX c #A8E9B6",
"tX c #B0EAAD",
"yX c #8ADAD7",
"uX c #99D7D6",
"iX c #8AC8E6",
"pX c #97C6E5",
"aX c #8FE6C7",
"sX c #A8CCDB",
"dX c #B5C8D8",
"fX c #AED8CB",
"gX c #A5C3E3",
"hX c #B2C1E0",
"jX c #A3E5C2",
"kX c #DEB9BD",
"lX c #FB9194",
"zX c #F092B4",
"xX c #F1B295",
"cX c #E9A8B6",
"vX c #EAB0AD",
"bX c #DA8AD7",
"nX c #D799D6",
"mX c #C88AE6",
"MX c #C697E5",
"NX c #CCA8DB",
"BX c #C8B5D8",
"VX c #D8AECB",
"CX c #C3A5E3",
"ZX c #C1B2E0",
"AX c #E68FC7",
"SX c #E5A3C2",
"DX c #D6D69C",
"FX c #D0D0B2",
"GX c #C4E88C",
"HX c #C1E5A6",
"JX c #E8C48C",
"KX c #E5C1A6",
"LX c #C9C9C6",
"PX c #C3C3D3",
"IX c #CBCBC1",
"                          0.0.9.9.9.0X0X0X0X                          ",
"                    6.6.0.8.w.q.q.q.q.qXqXqXeXeXeX                    ",
"                O.8.8.8.7.w.g.g.f.aXaXqXjXjXrXrXeXHXGX                ",
"              O.+.+.8.i.i.g.g.f.f.f.f.aXaXjXjXjXrXtXHXGX              ",
"             .o.5.5.t.t.g.a.a.a.p.p.yXyXuXaXfXjXfXwXwXHXDX            ",
"           .o.o.%.%.t.t.a.a.a.p.p.p.yXyXuXuXuXfXfXfXLXFXHXDX          ",
"         ...X.#.%.t.e.r.r.r.s.p.d.p.iXiXpXuXsXsXLXfXLXIXFXFXDX        ",
"      } ..X.@.#.$.$.r.r.y.s.s.s.d.iXiXiXpXpXgXsXdXPXPXLXLXIXKXJX      ",
"    } | | ] @.$.$.u.u.u.y.s.s.d.d.d.1XiXpXpXgXgXhXhXPXPXPXkXkXKXJX    ",
"    T E X.] ] [ [ u.u.;.;.;.4.3.3.3.1X1X1X6X6X6XhXhXBXBXVXLXkXKXxX    ",
"  T E W ] ] \' [ [ { =.:.4.4.4.4.3.1X1X2X2X6X6X9X8XZXZXZXPXVXVXSXvXxX  ",
"  T E ! ` \' \' { =.*.*.:.-.4.4.3.2.2.1X2X2X2X9X9X7X7XZXCXNXVXkXSXvXxX  ",
"  T R ! / \' \' { { *.*.:.-.-.2.1.2.2.>X2X2X5X5X5X7X7XCXMXNXnXVXSXcXxX  ",
"U Y R ! / ^ ^ _ _ *.&.&.1.1.1.1.<.>X>X>X<X<X<X4X4X7XMXMXnXnXnXSXzXzXlX",
"U Y Y Q / ^ ( _ ) &.*.&.&.1.1.<.<.<.>X>X<X<X4X4X4XMXMXMXMXnXAXAXAXzXlX",
"U Y Y Q ~ ~ ( _ ) &.&.&.1.>.>.>.,.,.:X>X,X,X<X4X3X3XMXmXbXbXnXAXAXzXlX",
": Y Q Q ~ ~ ( ( ) S S &.>.>.>.,.,.,.:XG.,X,X3X3X3X3XmXmXmXbXbXAXzX.XlX",
": , 3 3 q ( e r r &.S D D K K >.P :X:XG.H.,XH.Y.T.T.T.*X*X$X$X-XAX.X|.",
": , 3 3 q q e e r S S D D D K P P P G.G.H.H.Y.Y.T.T.*X*X*X$X$X-X-X.X|.",
": , 4 3 w q t e t S D F D K I P L G.F.G.J.H.J.Y.T.R.*X*X*X$X%X-XXX.X|.",
"> < < 4 w 0 0 t t F F F I I I I L F.F.F.J.J.Y.R.R.R.&X&X%X%X%X;XXXXX X",
"> < < 2 w 0 t t t F F F Z I I L L L F.F.J.J.L.L.R.@X&X&X&X%X%X;XXXXX X",
"  < - 2 6 7 9 t 9 9 V Z Z Z I H H F.D.F.D.J.L.L.I.@X@X@XOX%X=X=X{.[.  ",
"  = - - 6 7 7 9 9 V V A Z J J H H H H D.D.L.L.U.I.I.#XOXOX+X+X=X}.[.  ",
"  = ; ; 5 5 5 8 B B 9 A C C J J G D.D.D.D.D.U.S.U.#X#X#XoX+X+X=X[.[.  ",
"    X ; 1 5 5 8 8 B z z z J N J G M M D.N.D.S.S.P.S.`.oX\'.+X].(.[.    ",
"    . . X 1 * & & l l z z N N M M M M.M.N.S.S.S.S.P.`.`._.\'.^.(./.    ",
"      . # # $ * & l l l z N N M M M M.M.N.N.S.A.A.`.`._.\'.^.^.(.      ",
"        X @ # % % h l k k N v m m m m.m.b.N.C.C.`.Z.).).~.^.Q.        ",
"          @ @ # % % h k v v v v m m.v.v.b.n.b.C.Z.Z.).~.!.Q.          ",
"            + O p p p j j n v b b b v.v.n.n.V.Z.V.x.~.!.Q.            ",
"              o O O g g g c c x x x c.c.c.B.B.B.B.W.W.E.              ",
"                o O y u f f f f f c.x j.j.j.j.z.z.k.E.                ",
"                    y y i f f d d j.j.j.j.j.k.k.k.                    ",
"                          s s a a a a h.h.h.                          "
};
static Fl_Pixmap image_key(idata_key);

inline void PsmUI::cb_albedoTab_i(Fl_Group*, void*) {
  view->setMode(PsmView::ALBEDOS);
}
void PsmUI::cb_albedoTab(Fl_Group* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->user_data()))->cb_albedoTab_i(o,v);
}

inline void PsmUI::cb_surfaceTab_i(Fl_Group*, void*) {
  view->setMode(PsmView::SURFACE);
}
void PsmUI::cb_surfaceTab(Fl_Group* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->user_data()))->cb_surfaceTab_i(o,v);
}

inline void PsmUI::cb_useAlbedos_i(Fl_Check_Button*, void*) {
  view->redraw();
}
void PsmUI::cb_useAlbedos(Fl_Check_Button* o, void* v) {
  ((PsmUI*)(o->parent()->parent()->parent()->user_data()))->cb_useAlbedos_i(o,v);
}

PsmUI::PsmUI() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = mainWindow = new Fl_Double_Window(512, 472, "Photometric Stereo");
    w = o;
    o->user_data((void*)(this));
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 512, 25);
      o->menu(menu_);
    }
    { PsmView* o = view = new PsmView(0, 25, 512, 340);
      o->box(FL_NO_BOX);
      o->color(FL_BACKGROUND_COLOR);
      o->selection_color(FL_BACKGROUND_COLOR);
      o->labeltype(FL_NORMAL_LABEL);
      o->labelfont(0);
      o->labelsize(14);
      o->labelcolor(FL_BLACK);
      o->align(FL_ALIGN_CENTER);
      o->when(FL_WHEN_RELEASE);
    }
    { Fl_Tabs* o = tabs = new Fl_Tabs(5, 370, 500, 65);
      o->callback((Fl_Callback*)cb_tabs);
      { Fl_Group* o = sourcesTab = new Fl_Group(5, 370, 500, 40, "Sources");
        o->callback((Fl_Callback*)cb_sourcesTab);
        o->deactivate();
        { Fl_Counter* o = imageNum = new Fl_Counter(180, 380, 45, 20, "Show Image #:");
          o->minimum(0);
          o->maximum(12);
          o->step(1);
          o->callback((Fl_Callback*)cb_imageNum);
          o->align(FL_ALIGN_LEFT);
          o->type(FL_SIMPLE_COUNTER);
        }
        { Fl_Check_Button* o = showMask = new Fl_Check_Button(320, 380, 20, 20, "Show Mask");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_showMask);
        }
        o->end();
      }
      { Fl_Group* o = normalsTab = new Fl_Group(5, 370, 500, 40, "Normals");
        o->callback((Fl_Callback*)cb_normalsTab);
        o->hide();
        o->deactivate();
        { Fl_Choice* o = normalsMode = new Fl_Choice(110, 380, 110, 20, "Show as:");
          o->down_box(FL_BORDER_BOX);
          o->callback((Fl_Callback*)cb_normalsMode);
          o->menu(menu_normalsMode);
        }
        { Fl_Counter* o = needleSpacing = new Fl_Counter(280, 380, 35, 20, "Needle Spacing");
          o->minimum(5);
          o->maximum(100);
          o->step(5);
          o->value(10);
          o->callback((Fl_Callback*)cb_needleSpacing);
          o->align(FL_ALIGN_RIGHT);
          o->deactivate();
          o->type(FL_SIMPLE_COUNTER);
        }
        { Fl_Button* o = new Fl_Button(465, 373, 35, 35);
          o->tooltip("Color Key for RGB mode");
          o->image(image_key);
        }
        o->end();
      }
      { Fl_Group* o = albedoTab = new Fl_Group(5, 370, 500, 40, "Albedo Map");
        o->callback((Fl_Callback*)cb_albedoTab);
        o->hide();
        o->deactivate();
        o->end();
      }
      { Fl_Group* o = surfaceTab = new Fl_Group(5, 370, 500, 40, "Surface");
        o->callback((Fl_Callback*)cb_surfaceTab);
        o->hide();
        o->deactivate();
        { Fl_Check_Button* o = useAlbedos = new Fl_Check_Button(200, 380, 20, 20, "Use Albedo Map");
          o->down_box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_useAlbedos);
        }
        o->end();
      }
      o->end();
    }
    status = new Fl_Output(6, 442, 500, 25);
    o->end();
  }
}

void PsmUI::go() {
  mainWindow->show();
Fl::run();
}
