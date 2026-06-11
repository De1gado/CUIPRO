// UI THEME ---------------------------------------------------------------
// Cold Zone: blue-black surfaces, blue-gray secondary text, dirty white active states.
class colorScheme
{
	// Brand specific
	static int BrandColor()          { return UIColor.ZoneActivePaper(); }
	static int AccentColor()         { return UIColor.ZoneColdAccent(); }
	static int TertiaryColor()       { return UIColor.ZoneColdAccent(); }

	// Base typography
	static int PrimaryText()         { return UIColor.ZoneText(); }
	static int SecondaryText()       { return UIColor.ZoneTextMuted(); }
	static int TextHover()           { return UIColor.ZoneText(); }
	static int DisabledText()        { return UIColor.ZoneTextDim(); }

	// Global UI elements
	static int ButtonHover()         { return UIColor.ZoneText(); }
	static int Icons()               { return UIColor.ZoneText(); }
	static int LogOutTimer()         { return UIColor.ZoneActivePaper(); }
	static int Separator()           { return UIColor.ZoneBorderDim(); }
	static int Loadingbar()          { return UIColor.ZoneActivePaper(); }

	// Buttons
	static int BtnText()             { return PrimaryText(); }
	static int BtnHoverText()        { return UIColor.ZoneActiveText(); }
	static int BtnSolidBG()          { return UIColor.ZonePanel(); }
	static int BtnSolidHoverBG()     { return UIColor.ZoneActivePaper(); }
	static int BtnIcon()             { return Icons(); }
	static int BtnDangerBG()         { return UIColor.ZoneDanger(); }
	static int BtnDangerHoverBG()    { return UIColor.ZoneDangerDark(); }

	// Tabs
	static int TabIdle()             { return SecondaryText(); }
	static int TabHoverColor()       { return BrandColor(); }
	static int TabSelectedColor()    { return UIColor.ZoneActiveText(); }
	static int TabBackground()       { return UIColor.ZoneActivePaper(); }
	static int TabPanelBackground()  { return UIColor.ZonePanelSoft(); }

	// Shader colors
	static int TopShader()           { return UIColor.ZoneBlack(); }
	static int BottomShader()        { return UIColor.ZoneBlack(); }

	// Loading screen
	static int TipText()             { return PrimaryText(); }
	static int LoadingMsg()          { return PrimaryText(); }
	static int TipHeader()           { return AccentColor(); }
	static int TipLine()             { return UIColor.ZoneBorderDim(); }

	// Main menu
	static int NavIcon()             { return PrimaryText(); }
	static int SurvivorBox()         { return UIColor.ZonePanelSoft(); }
	static int StatsBox()            { return UIColor.ZonePanelSoft(); }
	static int MenuTint()            { return ARGB(150, 2, 5, 7); }
	static int BackgroundTone()      { return ARGB(255, 132, 154, 170); }

	// Dialogs
	static int DialogPanel()         { return UIColor.ZoneSurface(); }
	static int DialogBorder()        { return UIColor.ZoneBorderDim(); }
	static int Warning()             { return UIColor.ZoneDanger(); }

	// Options page
	static int OptionHeaders()       { return BrandColor(); }
	static int OptionLine()          { return UIColor.ZoneBorderDim(); }
	static int OptionInputColors()   { return BrandColor(); }
	static int OptionSliderColors()  { return BrandColor(); }
	static int OptionSelectionText() { return BrandColor(); }
	static int OptionCaretColors()   { return BrandColor(); }
	static int OptionIconHover()     { return TextHover(); }
	static int OptionIconNormal()    { return PrimaryText(); }
	static int OptionBGHover()       { return UIColor.ZonePanelSoft(); }
}
