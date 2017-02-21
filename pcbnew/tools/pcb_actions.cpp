/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2013-2016 CERN
 * Copyright (C) 2016 KiCad Developers, see AUTHORS.txt for contributors.
 * @author Maciej Suminski <maciej.suminski@cern.ch>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include "pcb_actions.h"
#include <tool/action_manager.h>
#include <pcbnew_id.h>
#include <layers_id_colors_and_visibility.h>
#include <bitmaps.h>
#include <wx/defs.h>
#include <hotkeys.h>

// These members are static in class PCB_ACTIONS: Build them here:

// Selection tool actions
TOOL_ACTION PCB_ACTIONS::selectionActivate( "pcbnew.InteractiveSelection",
        AS_GLOBAL, 0,
        "", "", NULL, AF_ACTIVATE ); // No description, it is not supposed to be shown anywhere

TOOL_ACTION PCB_ACTIONS::selectionCursor( "pcbnew.InteractiveSelection.Cursor",
        AS_GLOBAL, 0,
        "", "" );    // No description, it is not supposed to be shown anywhere

TOOL_ACTION PCB_ACTIONS::selectItem( "pcbnew.InteractiveSelection.SelectItem",
        AS_GLOBAL, 0,
        "", "" );    // No description, it is not supposed to be shown anywhere

TOOL_ACTION PCB_ACTIONS::unselectItem( "pcbnew.InteractiveSelection.UnselectItem",
        AS_GLOBAL, 0,
        "", "" );    // No description, it is not supposed to be shown anywhere

TOOL_ACTION PCB_ACTIONS::selectionClear( "pcbnew.InteractiveSelection.Clear",
        AS_GLOBAL, 0,
        "", "" );    // No description, it is not supposed to be shown anywhere

TOOL_ACTION PCB_ACTIONS::selectConnection( "pcbnew.InteractiveSelection.SelectConnection",
        AS_GLOBAL, 'U',
        _( "Trivial Connection" ), _( "Selects a connection between two junctions." ) );

TOOL_ACTION PCB_ACTIONS::selectCopper( "pcbnew.InteractiveSelection.SelectCopper",
        AS_GLOBAL, 'I',
        _( "Copper Connection" ), _( "Selects whole copper connection." ) );

TOOL_ACTION PCB_ACTIONS::selectNet( "pcbnew.InteractiveSelection.SelectNet",
        AS_GLOBAL, 0,
        _( "Whole Net" ), _( "Selects all tracks & vias belonging to the same net." ) );

TOOL_ACTION PCB_ACTIONS::selectSameSheet( "pcbnew.InteractiveSelection.SelectSameSheet",
        AS_GLOBAL,  'P',
        _( "Same Sheet" ), _( "Selects all modules and tracks in the same schematic sheet" ) );

TOOL_ACTION PCB_ACTIONS::find( "pcbnew.InteractiveSelection.Find",
        AS_GLOBAL, 0, //TOOL_ACTION::LegacyHotKey( HK_FIND_ITEM ), // handled by wxWidgets
        _( "Find Item" ), _( "Searches the document for an item" ), find_xpm );

TOOL_ACTION PCB_ACTIONS::findMove( "pcbnew.InteractiveSelection.FindMove",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_GET_AND_MOVE_FOOTPRINT ) );


// Edit tool actions
TOOL_ACTION PCB_ACTIONS::editFootprintInFpEditor( "pcbnew.InteractiveEdit.editFootprintInFpEditor",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_EDIT_MODULE_WITH_MODEDIT ),
        _( "Open in Footprint Editor" ),
        _( "Opens the selected footprint in the Footprint Editor" ),
        module_editor_xpm );

TOOL_ACTION PCB_ACTIONS::copyPadToSettings( "pcbnew.InteractiveEdit.copyPadToSettings",
        AS_GLOBAL, 0,
        _( "Copy Pad Settings to Current Settings" ),
        _( "Copies the properties of selected pad to the current template pad settings." ) );

TOOL_ACTION PCB_ACTIONS::copySettingsToPads( "pcbnew.InteractiveEdit.copySettingsToPads",
        AS_GLOBAL, 0,
        _( "Copy Current Settings to Pads" ),
        _( "Copies the current template pad settings to the selected pad(s)." ) );

TOOL_ACTION PCB_ACTIONS::globalEditPads( "pcbnew.InteractiveEdit.globalPadEdit",
        AS_GLOBAL, 0,
        _( "Global Pad Edition" ),
        _( "Changes pad properties globally." ), push_pad_settings_xpm );

TOOL_ACTION PCB_ACTIONS::editActivate( "pcbnew.InteractiveEdit",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_MOVE_ITEM ),
        _( "Move" ), _( "Moves the selected item(s)" ), move_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::duplicate( "pcbnew.InteractiveEdit.duplicate",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_DUPLICATE_ITEM ),
        _( "Duplicate" ), _( "Duplicates the selected item(s)" ), duplicate_module_xpm );

TOOL_ACTION PCB_ACTIONS::duplicateIncrement( "pcbnew.InteractiveEdit.duplicateIncrementPads",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_DUPLICATE_ITEM_AND_INCREMENT ),
        _( "Duplicate" ), _( "Duplicates the selected item(s), incrementing pad numbers" ) );

TOOL_ACTION PCB_ACTIONS::moveExact( "pcbnew.InteractiveEdit.moveExact",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_MOVE_ITEM_EXACT ),
        _( "Move Exactly..." ), _( "Moves the selected item(s) by an exact amount" ),
        move_module_xpm );

TOOL_ACTION PCB_ACTIONS::createArray( "pcbnew.InteractiveEdit.createArray",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_CREATE_ARRAY ),
        _( "Create Array" ), _( "Create array" ), array_module_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::rotateCw( "pcbnew.InteractiveEdit.rotateCw",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ROTATE_ITEM ),
        _( "Rotate Clockwise" ), _( "Rotates selected item(s) clockwise" ),
        rotate_cw_xpm, AF_NONE, (void*) 1 );

TOOL_ACTION PCB_ACTIONS::rotateCcw( "pcbnew.InteractiveEdit.rotateCcw",
        AS_GLOBAL, MD_SHIFT + 'R',
        _( "Rotate Counter-clockwise" ), _( "Rotates selected item(s) counter-clockwise" ),
        rotate_ccw_xpm, AF_NONE, (void*) -1 );

TOOL_ACTION PCB_ACTIONS::flip( "pcbnew.InteractiveEdit.flip",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_FLIP_ITEM ),
        _( "Flip" ), _( "Flips selected item(s)" ), swap_layer_xpm );

TOOL_ACTION PCB_ACTIONS::mirror( "pcbnew.InteractiveEdit.mirror",
        AS_GLOBAL, 0,
        _( "Mirror" ), _( "Mirrors selected item" ), mirror_h_xpm );

TOOL_ACTION PCB_ACTIONS::remove( "pcbnew.InteractiveEdit.remove",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_BACK_SPACE ),
        _( "Remove" ), _( "Deletes selected item(s)" ), delete_xpm,
        AF_NONE, (void*) REMOVE_FLAGS::NORMAL );

TOOL_ACTION PCB_ACTIONS::removeAlt( "pcbnew.InteractiveEdit.removeAlt",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_DELETE ),
        _( "Remove (Alternative)" ), _( "Deletes selected item(s)" ), delete_xpm,
        AF_NONE, (void*) REMOVE_FLAGS::ALT );

TOOL_ACTION PCB_ACTIONS::exchangeFootprints( "pcbnew.InteractiveEdit.ExchangeFootprints",
        AS_GLOBAL, 0,
        _( "Exchange Footprint(s)" ), _( "Change the footprint used for modules" ),
        import_module_xpm );


TOOL_ACTION PCB_ACTIONS::properties( "pcbnew.InteractiveEdit.properties",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_EDIT_ITEM ),
        _( "Properties..." ), _( "Displays item properties dialog" ), editor_xpm );

TOOL_ACTION PCB_ACTIONS::editModifiedSelection( "pcbnew.InteractiveEdit.ModifiedSelection",
        AS_GLOBAL, 0,
        "", "" );


// Drawing tool actions
TOOL_ACTION PCB_ACTIONS::drawLine( "pcbnew.InteractiveDrawing.line",
        AS_GLOBAL, 0,
        _( "Draw Line" ), _( "Draw a line" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawCircle( "pcbnew.InteractiveDrawing.circle",
        AS_GLOBAL, 0,
        _( "Draw Circle" ), _( "Draw a circle" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawArc( "pcbnew.InteractiveDrawing.arc",
        AS_GLOBAL, 0,
        _( "Draw Arc" ), _( "Draw an arc" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::placeText( "pcbnew.InteractiveDrawing.text",
        AS_GLOBAL, 0,
        _( "Add Text" ), _( "Add a text" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawDimension( "pcbnew.InteractiveDrawing.dimension",
        AS_GLOBAL, 0,
        _( "Add Dimension" ), _( "Add a dimension" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawZone( "pcbnew.InteractiveDrawing.zone",
        AS_GLOBAL, 0,
        _( "Add Filled Zone" ), _( "Add a filled zone" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawKeepout( "pcbnew.InteractiveDrawing.keepout",
        AS_GLOBAL, 0,
        _( "Add Keepout Area" ), _( "Add a keepout area" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawZoneCutout( "pcbnew.InteractiveDrawing.zoneCutout",
        AS_GLOBAL, 0,
        _( "Add a Zone Cutout" ), _( "Add a cutout area of an existing zone" ),
        add_zone_cutout_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drawSimilarZone( "pcbnew.InteractiveDrawing.similarZone",
        AS_GLOBAL, 0,
        _( "Add a Similar Zone" ), _( "Add a zone with the same settings as an existing zone" ),
        add_zone_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::placeDXF( "pcbnew.InteractiveDrawing.placeDXF",
        AS_GLOBAL, 0,
        "Place DXF", "", NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::setAnchor( "pcbnew.InteractiveDrawing.setAnchor",
        AS_GLOBAL, 0,
        _( "Place the Footprint Anchor" ), _( "Place the footprint anchor" ),
        NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::incWidth( "pcbnew.InteractiveDrawing.incWidth",
        AS_CONTEXT, '+',
        _( "Increase Line Width" ), _( "Increase the line width" ) );

TOOL_ACTION PCB_ACTIONS::decWidth( "pcbnew.InteractiveDrawing.decWidth",
        AS_CONTEXT, '-',
        _( "Decrease Line Width" ), _( "Decrease the line width" ) );

TOOL_ACTION PCB_ACTIONS::arcPosture( "pcbnew.InteractiveDrawing.arcPosture",
        AS_CONTEXT, TOOL_ACTION::LegacyHotKey( HK_SWITCH_TRACK_POSTURE ),
        _( "Switch Arc Posture" ), _( "Switch the arc posture" ) );


// View Controls
TOOL_ACTION PCB_ACTIONS::zoomIn( "common.Control.zoomIn",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZOOM_IN ),
        _( "Zoom In" ), "", zoom_in_xpm );

TOOL_ACTION PCB_ACTIONS::zoomOut( "common.Control.zoomOut",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZOOM_OUT ),
        _( "Zoom Out" ), "", zoom_out_xpm );

TOOL_ACTION PCB_ACTIONS::zoomInCenter( "common.Control.zoomInCenter",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::zoomOutCenter( "common.Control.zoomOutCenter",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::zoomCenter( "common.Control.zoomCenter",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZOOM_CENTER ),
        _( "Center" ), "", zoom_center_on_screen_xpm );

TOOL_ACTION PCB_ACTIONS::zoomFitScreen( "common.Control.zoomFitScreen",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZOOM_AUTO ),
        _( "Zoom Auto" ), "", zoom_fit_in_page_xpm );

TOOL_ACTION PCB_ACTIONS::zoomPreset( "common.Control.zoomPreset",
        AS_GLOBAL, 0,
        "", "" );


// Display modes
TOOL_ACTION PCB_ACTIONS::trackDisplayMode( "pcbnew.Control.trackDisplayMode",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_TRACK_DISPLAY_MODE ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::padDisplayMode( "pcbnew.Control.padDisplayMode",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::viaDisplayMode( "pcbnew.Control.viaDisplayMode",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::zoneDisplayEnable( "pcbnew.Control.zoneDisplayEnable",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::zoneDisplayDisable( "pcbnew.Control.zoneDisplayDisable",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::zoneDisplayOutlines( "pcbnew.Control.zoneDisplayOutlines",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::highContrastMode( "pcbnew.Control.highContrastMode",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_HIGHCONTRAST_MODE ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::highContrastInc( "pcbnew.Control.highContrastInc",
        AS_GLOBAL, '>',
        "", "" );

TOOL_ACTION PCB_ACTIONS::highContrastDec( "pcbnew.Control.highContrastDec",
        AS_GLOBAL, '<',
        "", "" );


// Layer control
TOOL_ACTION PCB_ACTIONS::layerTop( "pcbnew.Control.layerTop",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_COMPONENT ),
        "", "", NULL, AF_NONE, (void*) F_Cu );

TOOL_ACTION PCB_ACTIONS::layerInner1( "pcbnew.Control.layerInner1",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_INNER1 ),
        "", "", NULL, AF_NONE, (void*) In1_Cu );

TOOL_ACTION PCB_ACTIONS::layerInner2( "pcbnew.Control.layerInner2",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_INNER2 ),
        "", "", NULL, AF_NONE, (void*) In2_Cu );

TOOL_ACTION PCB_ACTIONS::layerInner3( "pcbnew.Control.layerInner3",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_INNER3 ),
        "", "", NULL, AF_NONE, (void*) In3_Cu );

TOOL_ACTION PCB_ACTIONS::layerInner4( "pcbnew.Control.layerInner4",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_INNER4 ),
        "", "", NULL, AF_NONE, (void*) In4_Cu );

TOOL_ACTION PCB_ACTIONS::layerInner5( "pcbnew.Control.layerInner5",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_INNER5 ),
        "", "", NULL, AF_NONE, (void*) In5_Cu );

TOOL_ACTION PCB_ACTIONS::layerInner6( "pcbnew.Control.layerInner6",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_INNER6 ),
        "", "", NULL, AF_NONE, (void*) In6_Cu );

TOOL_ACTION PCB_ACTIONS::layerBottom( "pcbnew.Control.layerBottom",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_COPPER ),
        "", "", NULL, AF_NONE, (void*) B_Cu );

TOOL_ACTION PCB_ACTIONS::layerNext( "pcbnew.Control.layerNext",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_NEXT ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::layerPrev( "pcbnew.Control.layerPrev",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_LAYER_TO_PREVIOUS ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::layerToggle( "pcbnew.Control.layerToggle",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ADD_THROUGH_VIA ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::layerAlphaInc( "pcbnew.Control.layerAlphaInc",
        AS_GLOBAL, '}',
        "", "" );

TOOL_ACTION PCB_ACTIONS::layerAlphaDec( "pcbnew.Control.layerAlphaDec",
        AS_GLOBAL, '{',
        "", "" );

TOOL_ACTION PCB_ACTIONS::layerChanged( "pcbnew.Control.layerChanged",
        AS_GLOBAL, 0,
        "", "", NULL, AF_NOTIFY );


// Grid control
TOOL_ACTION PCB_ACTIONS::gridFast1( "common.Control.gridFast1",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_GRID_TO_FASTGRID1 ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::gridFast2( "common.Control.gridFast2",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_GRID_TO_FASTGRID2 ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::gridNext( "common.Control.gridNext",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_GRID_TO_NEXT ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::gridPrev( "common.Control.gridPrev",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_GRID_TO_PREVIOUS ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::gridSetOrigin( "common.Control.gridSetOrigin",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SET_GRID_ORIGIN ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::gridResetOrigin( "common.Control.gridResetOrigin",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_RESET_GRID_ORIGIN ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::gridPreset( "common.Control.gridPreset",
        AS_GLOBAL, 0,
        "", "" );

// Track & via size control
TOOL_ACTION PCB_ACTIONS::trackWidthInc( "pcbnew.EditorControl.trackWidthInc",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_TRACK_WIDTH_TO_NEXT ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::trackWidthDec( "pcbnew.EditorControl.trackWidthDec",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_TRACK_WIDTH_TO_PREVIOUS ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::viaSizeInc( "pcbnew.EditorControl.viaSizeInc",
        AS_GLOBAL, '\'',
        "", "" );

TOOL_ACTION PCB_ACTIONS::viaSizeDec( "pcbnew.EditorControl.viaSizeDec",
        AS_GLOBAL, '\\',
        "", "" );

TOOL_ACTION PCB_ACTIONS::trackViaSizeChanged( "pcbnew.EditorControl.trackViaSizeChanged",
        AS_GLOBAL, 0,
        "", "", NULL, AF_NOTIFY );


// Zone actions
TOOL_ACTION PCB_ACTIONS::zoneFill( "pcbnew.EditorControl.zoneFill",
        AS_GLOBAL, 0,
        _( "Fill" ), _( "Fill zone(s)" ), fill_zone_xpm );

TOOL_ACTION PCB_ACTIONS::zoneFillAll( "pcbnew.EditorControl.zoneFillAll",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZONE_FILL_OR_REFILL ),
        _( "Fill All" ), _( "Fill all zones" ) );

TOOL_ACTION PCB_ACTIONS::zoneUnfill( "pcbnew.EditorControl.zoneUnfill",
        AS_GLOBAL, 0,
        _( "Unfill" ), _( "Unfill zone(s)" ), zone_unfill_xpm );

TOOL_ACTION PCB_ACTIONS::zoneUnfillAll( "pcbnew.EditorControl.zoneUnfillAll",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZONE_REMOVE_FILLED ),
        _( "Unfill All" ), _( "Unfill all zones" ) );

TOOL_ACTION PCB_ACTIONS::zoneMerge( "pcbnew.EditorControl.zoneMerge",
        AS_GLOBAL, 0,
        _( "Merge Zones" ), _( "Merge zones" ) );

TOOL_ACTION PCB_ACTIONS::zoneDuplicate( "pcbnew.EditorControl.zoneDuplicate",
        AS_GLOBAL, 0,
        _( "Duplicate Zone onto Layer" ), _( "Duplicate zone outline onto a different layer" ),
        zone_duplicate_xpm );


TOOL_ACTION PCB_ACTIONS::placeTarget( "pcbnew.EditorControl.placeTarget",
        AS_GLOBAL, 0,
        _( "Add Layer Alignment Target" ), _( "Add a layer alignment target" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::placeModule( "pcbnew.EditorControl.placeModule",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ADD_MODULE ),
        _( "Add Footprint" ), _( "Add a footprint" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::drillOrigin( "pcbnew.EditorControl.drillOrigin",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::crossProbeSchToPcb( "pcbnew.EditorControl.crossProbSchToPcb",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::toggleLock( "pcbnew.EditorControl.toggleLock",
        AS_GLOBAL, 'L',
        "Toggle Lock", "" );

TOOL_ACTION PCB_ACTIONS::lock( "pcbnew.EditorControl.lock",
        AS_GLOBAL, 0,
        _( "Lock" ), "" );

TOOL_ACTION PCB_ACTIONS::unlock( "pcbnew.EditorControl.unlock",
        AS_GLOBAL, 0,
        _( "Unlock" ), "" );

TOOL_ACTION PCB_ACTIONS::appendBoard( "pcbnew.EditorControl.appendBoard",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::highlightNet( "pcbnew.EditorControl.highlightNet",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::highlightNetCursor( "pcbnew.EditorControl.highlightNetCursor",
        AS_GLOBAL, 0,
        "", "" );


// Module editor tools
TOOL_ACTION PCB_ACTIONS::placePad( "pcbnew.ModuleEditor.placePad",
        AS_GLOBAL, 0,
        _( "Add Pad" ), _( "Add a pad" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::enumeratePads( "pcbnew.ModuleEditor.enumeratePads",
        AS_GLOBAL, 0,
        _( "Enumerate Pads" ), _( "Enumerate pads" ), pad_enumerate_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::copyItems( "pcbnew.ModuleEditor.copyItems",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_COPY_ITEM ),
        _( "Copy" ), _( "Copy items" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::pasteItems( "pcbnew.ModuleEditor.pasteItems",
        AS_GLOBAL, MD_CTRL + int( 'V' ),
        _( "Paste" ), _( "Paste items" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::moduleEdgeOutlines( "pcbnew.ModuleEditor.graphicOutlines",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::moduleTextOutlines( "pcbnew.ModuleEditor.textOutlines",
       AS_GLOBAL, 0,
       "", "" );

// Pad tools
TOOL_ACTION PCB_ACTIONS::copyPadSettings(
        "pcbnew.PadTool.CopyPadSettings",
        AS_GLOBAL, 0,
        _( "Copy Pad Settings" ), _( "Copy current pad's settings to the board design settings" ),
        copy_pad_settings_xpm );

TOOL_ACTION PCB_ACTIONS::applyPadSettings(
        "pcbnew.PadTool.ApplyPadSettings",
        AS_GLOBAL, 0,
        _( "Apply Pad Settings" ), _( "Copy the board design settings pad properties to the current pad" ),
        apply_pad_settings_xpm );

TOOL_ACTION PCB_ACTIONS::pushPadSettings(
        "pcbnew.PadTool.PushPadSettings",
        AS_GLOBAL, 0,
        _( "Push Pad Settings" ), _( "Copy the current pad settings to other pads" ),
        push_pad_settings_xpm );

// Cursor control
TOOL_ACTION PCB_ACTIONS::cursorUp( "pcbnew.Control.cursorUp",
        AS_GLOBAL, WXK_UP, "", "", NULL, AF_NONE, (void*) CURSOR_UP );
TOOL_ACTION PCB_ACTIONS::cursorDown( "pcbnew.Control.cursorDown",
        AS_GLOBAL, WXK_DOWN, "", "" , NULL, AF_NONE, (void*) CURSOR_DOWN );
TOOL_ACTION PCB_ACTIONS::cursorLeft( "pcbnew.Control.cursorLeft",
        AS_GLOBAL, WXK_LEFT, "", "" , NULL, AF_NONE, (void*) CURSOR_LEFT );
TOOL_ACTION PCB_ACTIONS::cursorRight( "pcbnew.Control.cursorRight",
        AS_GLOBAL, WXK_RIGHT, "", "" , NULL, AF_NONE, (void*) CURSOR_RIGHT );

TOOL_ACTION PCB_ACTIONS::cursorUpFast( "pcbnew.Control.cursorUpFast",
        AS_GLOBAL, MD_CTRL + WXK_UP, "", "", NULL, AF_NONE, (void*) ( CURSOR_UP | CURSOR_FAST_MOVE ) );
TOOL_ACTION PCB_ACTIONS::cursorDownFast( "pcbnew.Control.cursorDownFast",
        AS_GLOBAL, MD_CTRL + WXK_DOWN, "", "" , NULL, AF_NONE, (void*) ( CURSOR_DOWN | CURSOR_FAST_MOVE ) );
TOOL_ACTION PCB_ACTIONS::cursorLeftFast( "pcbnew.Control.cursorLeftFast",
        AS_GLOBAL, MD_CTRL + WXK_LEFT, "", "" , NULL, AF_NONE, (void*) ( CURSOR_LEFT | CURSOR_FAST_MOVE ) );
TOOL_ACTION PCB_ACTIONS::cursorRightFast( "pcbnew.Control.cursorRightFast",
        AS_GLOBAL, MD_CTRL + WXK_RIGHT, "", "" , NULL, AF_NONE, (void*) ( CURSOR_RIGHT | CURSOR_FAST_MOVE ) );

TOOL_ACTION PCB_ACTIONS::cursorClick( "pcbnew.Control.cursorClick",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_LEFT_CLICK ),
        "", "", NULL, AF_NONE, (void*) CURSOR_CLICK );
TOOL_ACTION PCB_ACTIONS::cursorDblClick( "pcbnew.Control.cursorDblClick",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_LEFT_DCLICK ),
        "", "", NULL, AF_NONE, (void*) CURSOR_DBL_CLICK );

TOOL_ACTION PCB_ACTIONS::panUp( "pcbnew.Control.panUp",
        AS_GLOBAL, MD_SHIFT + WXK_UP, "", "", NULL, AF_NONE, (void*) CURSOR_UP );
TOOL_ACTION PCB_ACTIONS::panDown( "pcbnew.Control.panDown",
        AS_GLOBAL, MD_SHIFT + WXK_DOWN, "", "" , NULL, AF_NONE, (void*) CURSOR_DOWN );
TOOL_ACTION PCB_ACTIONS::panLeft( "pcbnew.Control.panLeft",
        AS_GLOBAL, MD_SHIFT + WXK_LEFT, "", "" , NULL, AF_NONE, (void*) CURSOR_LEFT );
TOOL_ACTION PCB_ACTIONS::panRight( "pcbnew.Control.panRight",
        AS_GLOBAL, MD_SHIFT + WXK_RIGHT, "", "" , NULL, AF_NONE, (void*) CURSOR_RIGHT );

// Miscellaneous
TOOL_ACTION PCB_ACTIONS::selectionTool( "pcbnew.Control.selectionTool",
        AS_GLOBAL, 0,
        "", "", NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::zoomTool( "pcbnew.Control.zoomTool",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ZOOM_SELECTION ),
        _( "Zoom to Selection" ), "", NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::pickerTool( "pcbnew.Picker", AS_GLOBAL, 0, "", "", NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::resetCoords( "pcbnew.Control.resetCoords",
        AS_GLOBAL, ' ',
        "", "" );

TOOL_ACTION PCB_ACTIONS::switchCursor( "pcbnew.Control.switchCursor",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::switchUnits( "pcbnew.Control.switchUnits",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_SWITCH_UNITS ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::deleteItemCursor( "pcbnew.Control.deleteItemCursor",
        AS_GLOBAL, 0,
        "", "" );

TOOL_ACTION PCB_ACTIONS::showHelp( "pcbnew.Control.showHelp",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_HELP ),
        "", "" );

TOOL_ACTION PCB_ACTIONS::toBeDone( "pcbnew.Control.toBeDone",
        AS_GLOBAL, 0,           // dialog saying it is not implemented yet
        "", "" );               // so users are aware of that


TOOL_ACTION PCB_ACTIONS::routerActivateSingle( "pcbnew.InteractiveRouter.SingleTrack",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_ADD_NEW_TRACK ),
        _( "Interactive Router (Single Tracks)" ),
        _( "Run push & shove router (single tracks)" ), ps_router_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerActivateDiffPair( "pcbnew.InteractiveRouter.DiffPair",
        AS_GLOBAL, '6',
        _( "Interactive Router (Differential Pairs)" ),
        _( "Run push & shove router (differential pairs)" ), ps_diff_pair_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerActivateSettingsDialog( "pcbnew.InteractiveRouter.SettingsDialog",
        AS_GLOBAL, 0,
        _( "Interactive Router Settings" ),
        _( "Open Interactive Router settings" ), NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerActivateDpDimensionsDialog( "pcbnew.InteractiveRouter.DpDimensionsDialog",
        AS_GLOBAL, 0,
        _( "Differential Pair Dimension settings" ),
        _( "Open Differential Pair Dimension settings" ), ps_diff_pair_gap_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerActivateTuneSingleTrace( "pcbnew.LengthTuner.TuneSingleTrack",
        AS_GLOBAL, '7',
        _( "Tune length of a single track" ), "", ps_tune_length_xpm, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerActivateTuneDiffPair( "pcbnew.LengthTuner.TuneDiffPair",
        AS_GLOBAL, '8',
        _( "Tune length of a differential pair" ), "", NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerActivateTuneDiffPairSkew( "pcbnew.LengthTuner.TuneDiffPairSkew",
        AS_GLOBAL, '9',
        _( "Tune skew of a differential pair" ), "", NULL, AF_ACTIVATE );

TOOL_ACTION PCB_ACTIONS::routerInlineDrag( "pcbnew.InteractiveRouter.InlineDrag",
        AS_GLOBAL, TOOL_ACTION::LegacyHotKey( HK_DRAG_TRACK_KEEP_SLOPE ),
        _( "Drag Track/Via" ), _( "Drags tracks and vias without breaking connections" ),
        drag_track_segment_xpm );

// Point editor
TOOL_ACTION PCB_ACTIONS::pointEditorAddCorner( "pcbnew.PointEditor.addCorner",
        AS_GLOBAL, 0,
        _( "Create Corner" ), _( "Create a corner" ), add_corner_xpm );

TOOL_ACTION PCB_ACTIONS::pointEditorRemoveCorner( "pcbnew.PointEditor.removeCorner",
        AS_GLOBAL, 0,
        _( "Remove Corner" ), _( "Remove corner" ), delete_xpm );

// Placement tool
TOOL_ACTION PCB_ACTIONS::alignTop( "pcbnew.Place.alignTop",
        AS_GLOBAL, 0,
        _( "Align to Top" ),
        _( "Aligns selected items to the top edge" ), up_xpm );

TOOL_ACTION PCB_ACTIONS::alignBottom( "pcbnew.Place.alignBottom",
        AS_GLOBAL, 0,
        _( "Align to Bottom" ),
        _( "Aligns selected items to the bottom edge" ), down_xpm );

TOOL_ACTION PCB_ACTIONS::alignLeft( "pcbnew.Place.alignLeft",
        AS_GLOBAL, 0,
        _( "Align to Left" ),
        _( "Aligns selected items to the left edge" ), left_xpm );

TOOL_ACTION PCB_ACTIONS::alignRight( "pcbnew.Place.alignRight",
        AS_GLOBAL, 0,
        _( "Align to Right" ),
        _( "Aligns selected items to the right edge" ), right_xpm );

TOOL_ACTION PCB_ACTIONS::distributeHorizontally( "pcbnew.Place.distributeHorizontally",
        AS_GLOBAL, 0,
        _( "Distribute Horizontally" ),
        _( "Distributes selected items along the horizontal axis" ), distribute_horizontal_xpm );

TOOL_ACTION PCB_ACTIONS::distributeVertically( "pcbnew.Place.distributeVertically",
        AS_GLOBAL, 0,
        _( "Distribute Vertically" ),
        _( "Distributes selected items along the vertical axis" ), distribute_vertical_xpm );


boost::optional<TOOL_EVENT> PCB_ACTIONS::TranslateLegacyId( int aId )
{
    switch( aId )
    {
    case ID_PCB_MODULE_BUTT:
        return PCB_ACTIONS::placeModule.MakeEvent();

    case ID_TRACK_BUTT:
        return PCB_ACTIONS::routerActivateSingle.MakeEvent();

    case ID_DIFF_PAIR_BUTT:
        return PCB_ACTIONS::routerActivateDiffPair.MakeEvent();

    case ID_TUNE_SINGLE_TRACK_LEN_BUTT:
        return PCB_ACTIONS::routerActivateTuneSingleTrace.MakeEvent();

    case ID_TUNE_DIFF_PAIR_LEN_BUTT:
        return PCB_ACTIONS::routerActivateTuneDiffPair.MakeEvent();

    case ID_TUNE_DIFF_PAIR_SKEW_BUTT:
        return PCB_ACTIONS::routerActivateTuneDiffPairSkew.MakeEvent();

    case ID_MENU_INTERACTIVE_ROUTER_SETTINGS:
        return PCB_ACTIONS::routerActivateSettingsDialog.MakeEvent();

    case ID_MENU_DIFF_PAIR_DIMENSIONS:
        return PCB_ACTIONS::routerActivateDpDimensionsDialog.MakeEvent();

    case ID_PCB_ZONES_BUTT:
        return PCB_ACTIONS::drawZone.MakeEvent();

    case ID_PCB_KEEPOUT_AREA_BUTT:
        return PCB_ACTIONS::drawKeepout.MakeEvent();

    case ID_PCB_ADD_LINE_BUTT:
    case ID_MODEDIT_LINE_TOOL:
        return PCB_ACTIONS::drawLine.MakeEvent();

    case ID_PCB_CIRCLE_BUTT:
    case ID_MODEDIT_CIRCLE_TOOL:
        return PCB_ACTIONS::drawCircle.MakeEvent();

    case ID_PCB_ARC_BUTT:
    case ID_MODEDIT_ARC_TOOL:
        return PCB_ACTIONS::drawArc.MakeEvent();

    case ID_PCB_ADD_TEXT_BUTT:
    case ID_MODEDIT_TEXT_TOOL:
        return PCB_ACTIONS::placeText.MakeEvent();

    case ID_PCB_DIMENSION_BUTT:
        return PCB_ACTIONS::drawDimension.MakeEvent();

    case ID_PCB_MIRE_BUTT:
        return PCB_ACTIONS::placeTarget.MakeEvent();

    case ID_MODEDIT_PAD_TOOL:
        return PCB_ACTIONS::placePad.MakeEvent();

    case ID_GEN_IMPORT_DXF_FILE:
        return PCB_ACTIONS::placeDXF.MakeEvent();

    case ID_MODEDIT_ANCHOR_TOOL:
        return PCB_ACTIONS::setAnchor.MakeEvent();

    case ID_PCB_PLACE_GRID_COORD_BUTT:
    case ID_MODEDIT_PLACE_GRID_COORD:
        return PCB_ACTIONS::gridSetOrigin.MakeEvent();

    case ID_ZOOM_IN:        // toolbar button "Zoom In"
        return PCB_ACTIONS::zoomInCenter.MakeEvent();

    case ID_ZOOM_OUT:       // toolbar button "Zoom In"
        return PCB_ACTIONS::zoomOutCenter.MakeEvent();

    case ID_ZOOM_PAGE:      // toolbar button "Fit on Screen"
        return PCB_ACTIONS::zoomFitScreen.MakeEvent();

    case ID_TB_OPTIONS_SHOW_TRACKS_SKETCH:
        return PCB_ACTIONS::trackDisplayMode.MakeEvent();

    case ID_TB_OPTIONS_SHOW_PADS_SKETCH:
        return PCB_ACTIONS::padDisplayMode.MakeEvent();

    case ID_TB_OPTIONS_SHOW_VIAS_SKETCH:
        return PCB_ACTIONS::viaDisplayMode.MakeEvent();

    case ID_TB_OPTIONS_SHOW_ZONES:
        return PCB_ACTIONS::zoneDisplayEnable.MakeEvent();

    case ID_TB_OPTIONS_SHOW_ZONES_DISABLE:
        return PCB_ACTIONS::zoneDisplayDisable.MakeEvent();

    case ID_TB_OPTIONS_SHOW_ZONES_OUTLINES_ONLY:
        return PCB_ACTIONS::zoneDisplayOutlines.MakeEvent();

    case ID_TB_OPTIONS_SHOW_MODULE_EDGE_SKETCH:
        return PCB_ACTIONS::moduleEdgeOutlines.MakeEvent();

    case ID_TB_OPTIONS_SHOW_MODULE_TEXT_SKETCH:
        return PCB_ACTIONS::moduleTextOutlines.MakeEvent();

    case ID_TB_OPTIONS_SHOW_HIGH_CONTRAST_MODE:
        return PCB_ACTIONS::highContrastMode.MakeEvent();

    case ID_FIND_ITEMS:
        return PCB_ACTIONS::find.MakeEvent();

    case ID_POPUP_PCB_GET_AND_MOVE_MODULE_REQUEST:
        return PCB_ACTIONS::findMove.MakeEvent();

    case ID_NO_TOOL_SELECTED:
        return PCB_ACTIONS::selectionTool.MakeEvent();

    case ID_ZOOM_SELECTION:
        return PCB_ACTIONS::zoomTool.MakeEvent();

    case ID_PCB_DELETE_ITEM_BUTT:
    case ID_MODEDIT_DELETE_TOOL:
        return PCB_ACTIONS::deleteItemCursor.MakeEvent();

    case ID_PCB_PLACE_OFFSET_COORD_BUTT:
        return PCB_ACTIONS::drillOrigin.MakeEvent();

    case ID_PCB_HIGHLIGHT_BUTT:
        return PCB_ACTIONS::highlightNetCursor.MakeEvent();

    case ID_APPEND_FILE:
        return PCB_ACTIONS::appendBoard.MakeEvent();

    case ID_PCB_SHOW_1_RATSNEST_BUTT:
        return PCB_ACTIONS::toBeDone.MakeEvent();
    }

    return boost::optional<TOOL_EVENT>();
}