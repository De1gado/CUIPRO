// COLOR PALETTE ---------------------------------------------------------
// Approved direction: Cold Zone / post-apocalyptic monochrome UI.
class UIColor
{
	// Core approved palette
	static int ZoneBlack()          { return ARGB(255, 2, 5, 7); };       // #020507
	static int ZoneDeepBlack()      { return ARGB(255, 7, 16, 24); };     // #071018
	static int ZoneNavy()           { return ARGB(255, 13, 23, 33); };    // #0D1721
	static int ZoneGraphite()       { return ARGB(255, 28, 39, 48); };    // #1C2730
	static int ZoneText()           { return ARGB(255, 228, 224, 208); }; // #E4E0D0
	static int ZoneTextMuted()      { return ARGB(235, 143, 168, 184); }; // #8FA8B8, cold secondary UI text
	static int ZoneTextDim()        { return ARGB(190, 91, 110, 124); };
	static int ZoneDanger()         { return ARGB(255, 127, 47, 47); };   // #7F2F2F
	static int ZoneDangerDark()     { return ARGB(255, 72, 22, 22); };
	static int ZoneColdAccent()     { return ARGB(255, 143, 168, 184); }; // #8FA8B8

	// Surface tokens
	static int ZonePanel()          { return ARGB(196, 2, 5, 7); };
	static int ZonePanelSoft()      { return ARGB(132, 7, 16, 24); };
	static int ZoneSurface()        { return ARGB(184, 13, 23, 33); };
	static int ZoneBorder()         { return ARGB(150, 143, 168, 184); };
	static int ZoneBorderDim()      { return ARGB(82, 143, 168, 184); };
	static int ZoneAgedPaper()      { return ARGB(255, 154, 150, 136); }; // #9A9688, use sparingly for worn scratches only
	static int ZoneActivePaper()    { return ARGB(245, 228, 224, 208); };
	static int ZoneActiveText()     { return ARGB(255, 2, 5, 7); };

	// Generic names used by older CUI code
	static int White()              { return ZoneText(); };
	static int Grey()               { return ZoneTextMuted(); };
	static int Black()              { return ZoneBlack(); };
	static int Transparent()        { return ARGB(1, 0, 0, 0); };
	static int SemiTransWhite()     { return ARGB(110, 228, 224, 208); };
	static int SemiTransBlack()     { return ARGB(121, 0, 0, 0); };

	// Compatibility aliases from the previous draft. Values now follow Cold Zone.
	static int DossierBlack()       { return ZoneBlack(); };
	static int DossierNavy()        { return ZoneDeepBlack(); };
	static int DossierPanel()       { return ZonePanel(); };
	static int DossierPanelSoft()   { return ZonePanelSoft(); };
	static int DossierSurface()     { return ZoneSurface(); };
	static int DossierBorder()      { return ZoneBorder(); };
	static int DossierText()        { return ZoneText(); };
	static int DossierTextMuted()   { return ZoneTextMuted(); };
	static int DossierTextDim()     { return ZoneTextDim(); };
	static int DossierAmber()       { return ZoneActivePaper(); };
	static int DossierAmberSoft()   { return ZoneColdAccent(); };
	static int DossierAmberDark()   { return ZoneBorderDim(); };
	static int DossierDanger()      { return ZoneDanger(); };
	static int DossierDangerDark()  { return ZoneDangerDark(); };
	static int DossierStamina()     { return ZoneColdAccent(); };
	static int DossierSuccess()     { return ZoneColdAccent(); };

	// R.O.Y.G.B.I.V compatibility
	static int Red()                { return ZoneDanger(); };
	static int Orange()             { return ZoneDanger(); };
	static int Yellow()             { return ZoneActivePaper(); };
	static int Green()              { return ZoneColdAccent(); };
	static int Blue()               { return ZoneColdAccent(); };
	static int Indigo()             { return ZoneNavy(); };
	static int Violet()             { return ZoneGraphite(); };

	// Social Network Colors
	static int Discord()            { return ARGB(255, 88, 101, 242); };
	static int Twitter()            { return ARGB(255, 29, 161, 242); };
	static int Facebook()           { return ARGB(255, 59, 89, 152); };
	static int YouTube()            { return ARGB(255, 205, 32, 31); };
	static int Instagram()          { return ARGB(255, 193, 42, 163); };
	static int Meta()               { return ARGB(255, 193, 42, 163); };
	static int Reddit()             { return ARGB(255, 102, 51, 204); };
	static int LinkedIn()           { return ARGB(255, 0, 119, 181); };
	static int Pinterest()          { return ARGB(255, 189, 8, 28); };
	static int Snapchat()           { return ARGB(255, 255, 252, 0); };
	static int TikTok()             { return ARGB(255, 1, 1, 1); };
	static int WhatsApp()           { return ARGB(255, 37, 211, 102); };
	static int Tumblr()             { return ARGB(255, 54, 70, 93); };
	static int Flickr()             { return ARGB(255, 244, 0, 131); };
	static int Vimeo()              { return ARGB(255, 26, 183, 234); };
	static int Skype()              { return ARGB(255, 0, 175, 240); };
	static int Slack()              { return ARGB(255, 74, 21, 75); };
	static int Medium()             { return ARGB(255, 2, 184, 117); };
	static int Quora()              { return ARGB(255, 170, 34, 0); };
	static int Dribbble()           { return ARGB(255, 234, 76, 137); };
	static int SoundCloud()         { return ARGB(255, 255, 85, 0); };
	static int Spotify()            { return ARGB(255, 30, 215, 96); };
	static int Twitch()             { return ARGB(255, 145, 70, 255); };
	static int Telegram()           { return ARGB(255, 0, 136, 204); };
	static int Mastodon()           { return ARGB(255, 99, 100, 255); };

	// Legacy Colorful UI names mapped to the approved palette
	static int cuiTeal()            { return ZoneColdAccent(); };
	static int cuiBlue()            { return ZoneNavy(); };
	static int cuiDarkBlue()        { return ZonePanelSoft(); };
	static int cuiSubtleRed()       { return ZoneDangerDark(); };
	static int cuiBrightRed()       { return ZoneDanger(); };
}
