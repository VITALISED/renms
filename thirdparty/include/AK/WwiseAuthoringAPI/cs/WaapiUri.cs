/*

The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Copyright (c) 2023 Audiokinetic Inc.

*/
public class ak
{
	public class wwise
	{
		public class core
		{
			/// <summary>Retrieve global Wwise information.</summary>
			public const string getInfo = "ak.wwise.core.getInfo";
			/// <summary>Retrieve information about the current project opened, including platforms, languages and project directories.</summary>
			public const string getProjectInfo = "ak.wwise.core.getProjectInfo";
			public class project
			{
				/// <summary>Saves the current project.</summary>
				public const string save = "ak.wwise.core.project.save";
				/// <summary>Sent when the project has been successfully loaded.</summary>
				public const string loaded = "ak.wwise.core.project.loaded";
				/// <summary>Sent when the project begins closing.</summary>
				public const string preClosed = "ak.wwise.core.project.preClosed";
				/// <summary>Sent when the after the project is completely closed.</summary>
				public const string postClosed = "ak.wwise.core.project.postClosed";
				/// <summary>Sent when the project has been saved.</summary>
				public const string saved = "ak.wwise.core.project.saved";
			}
			public class @object
			{
				/// <summary>Renames an object.</summary>
				public const string setName = "ak.wwise.core.object.setName";
				/// <summary>Sets an object's reference value. Refer to \ref wobjects_index for more information on the references available on each object type.</summary>
				public const string setReference = "ak.wwise.core.object.setReference";
				/// <summary>Sets a property value of an object for a specific platform. Refer to \ref wobjects_index for more information on the properties available on each object type. Refer to \ref ak_wwise_core_object_setreference to set a reference to an object. Refer to \ref ak_wwise_core_object_get to obtain the value of a property for an object.</summary>
				public const string setProperty = "ak.wwise.core.object.setProperty";
				/// <summary>Sets the randomizer values of a property of an object for a specific platform. Refer to \ref wobjects_index for more information on the properties available on each object type.</summary>
				public const string setRandomizer = "ak.wwise.core.object.setRandomizer";
				/// <summary>Sets the object's notes.</summary>
				public const string setNotes = "ak.wwise.core.object.setNotes";
				/// <summary>Gets the specified attenuation curve for a given attenuation object.</summary>
				public const string getAttenuationCurve = "ak.wwise.core.object.getAttenuationCurve";
				/// <summary>Sets the specified attenuation curve for a given attenuation object.</summary>
				public const string setAttenuationCurve = "ak.wwise.core.object.setAttenuationCurve";
				/// <summary>Creates an object of type 'type', as a child of 'parent'. Refer to \ref waapi_import for more information about creating objects. Also refer to \ref ak_wwise_core_audio_import to import audio files to Wwise.</summary>
				public const string create = "ak.wwise.core.object.create";
				/// <summary>Allows for batch processing of the following operations: Object creation in a child hierarchy, Object creation in a list, Setting name, notes, properties and references. Refer to \ref waapi_import for more information about creating objects. Also refer to \ref ak_wwise_core_audio_import to import audio files to Wwise.</summary>
				public const string set = "ak.wwise.core.object.set";
				/// <summary>Moves an object to the given parent. Returns the moved object.</summary>
				public const string move = "ak.wwise.core.object.move";
				/// <summary>Copies an object to the given parent.</summary>
				public const string copy = "ak.wwise.core.object.copy";
				/// <summary>Deletes the specified object.</summary>
				public const string delete = "ak.wwise.core.object.delete";
				/// <summary>Performs a query and returns the data, as specified in the options, for each object in the query result. The query can specify either a 'waql' argument or a 'from' argument with an optional 'transform' argument. Refer to \ref waql_introduction or \ref waapi_query for more information. Refer to \ref waapi_query_return to learn about options.</summary>
				public const string get = "ak.wwise.core.object.get";
				/// <summary>Compares properties and lists of the source object with those in the target object.</summary>
				public const string diff = "ak.wwise.core.object.diff";
				/// <summary>Pastes properties, references and lists from one object to any number of target objects. Only those properties, references and lists which differ between source and target are pasted. Refer to \ref wobjects_index for more information on the properties, references and lists available on each object type.</summary>
				public const string pasteProperties = "ak.wwise.core.object.pasteProperties";
				/// <summary>Retrieves the list of all object types registered in Wwise's object model. This function returns the equivalent of \ref wobjects_index .</summary>
				public const string getTypes = "ak.wwise.core.object.getTypes";
				/// <summary>Retrieves information about an object property. Note that this function does not return the value of a property. To retrieve the value of a property, refer to \ref ak_wwise_core_object_get and \ref waapi_query_return.</summary>
				public const string getPropertyInfo = "ak.wwise.core.object.getPropertyInfo";
				/// <summary>Retrieves the list of property and reference names for an object.</summary>
				public const string getPropertyNames = "ak.wwise.core.object.getPropertyNames";
				/// <summary>Retrieves the list of property and reference names for an object.</summary>
				public const string getPropertyAndReferenceNames = "ak.wwise.core.object.getPropertyAndReferenceNames";
				/// <summary>Returns true if a property is enabled based on the values of the properties it depends on.</summary>
				public const string isPropertyEnabled = "ak.wwise.core.object.isPropertyEnabled";
				/// <summary>Sent when an object reference is changed.</summary>
				public const string referenceChanged = "ak.wwise.core.object.referenceChanged";
				/// <summary>Sent when an object is renamed. Publishes the renamed object.</summary>
				public const string nameChanged = "ak.wwise.core.object.nameChanged";
				/// <summary>Sent when the object's notes are changed.</summary>
				public const string notesChanged = "ak.wwise.core.object.notesChanged";
				/// <summary>Sent when an object is created.</summary>
				public const string created = "ak.wwise.core.object.created";
				/// <summary>Sent prior to an object's deletion.</summary>
				public const string preDeleted = "ak.wwise.core.object.preDeleted";
				/// <summary>Sent following an object's deletion.</summary>
				public const string postDeleted = "ak.wwise.core.object.postDeleted";
				/// <summary>Sent when an object is added as a child to another object.</summary>
				public const string childAdded = "ak.wwise.core.object.childAdded";
				/// <summary>Sent when an object is removed from the children of another object.</summary>
				public const string childRemoved = "ak.wwise.core.object.childRemoved";
				/// <summary>Sent when one or many curves are changed.</summary>
				public const string curveChanged = "ak.wwise.core.object.curveChanged";
				/// <summary>Sent when an attenuation curve is changed.</summary>
				public const string attenuationCurveChanged = "ak.wwise.core.object.attenuationCurveChanged";
				/// <summary>Sent when an attenuation curve's link/unlink is changed.</summary>
				public const string attenuationCurveLinkChanged = "ak.wwise.core.object.attenuationCurveLinkChanged";
				/// <summary>Sent when the watched property of an object changes.</summary>
				public const string propertyChanged = "ak.wwise.core.object.propertyChanged";
			}
			public class switchContainer
			{
				/// <summary>Assigns a Switch Container's child to a Switch. This is the equivalent of doing a drag&drop of the child to a state in the Assigned Objects view. The child is always added at the end for each state.</summary>
				public const string addAssignment = "ak.wwise.core.switchContainer.addAssignment";
				/// <summary>Removes an assignment between a Switch Container's child and a State.</summary>
				public const string removeAssignment = "ak.wwise.core.switchContainer.removeAssignment";
				/// <summary>Returns the list of assignments between a Switch Container's children and states.</summary>
				public const string getAssignments = "ak.wwise.core.switchContainer.getAssignments";
				/// <summary>Sent when an assignment is added to a Switch Container.</summary>
				public const string assignmentAdded = "ak.wwise.core.switchContainer.assignmentAdded";
				/// <summary>Sent when an assignment is removed from a Switch Container.</summary>
				public const string assignmentRemoved = "ak.wwise.core.switchContainer.assignmentRemoved";
			}
			public class audio
			{
				/// <summary>Creates Wwise objects and imports audio files. This function uses the same importation processor available through the Tab Delimited import in the Audio File Importer. The function returns an array of all objects created, replaced or re-used. Use the options to specify how the objects are returned. For more information, refer to \ref waapi_import.</summary>
				public const string import = "ak.wwise.core.audio.import";
				/// <summary>Scripted object creation and audio file import from a tab-delimited file.</summary>
				public const string importTabDelimited = "ak.wwise.core.audio.importTabDelimited";
				/// <summary>Sent at the end of an import operation.</summary>
				public const string imported = "ak.wwise.core.audio.imported";
			}
			public class remote
			{
				/// <summary>Connects the Wwise Authoring application to a Wwise Sound Engine running executable. The host must be running code with communication enabled. If only "host" is provided, Wwise connects to the first Sound Engine instance found. To distinguish between different instances, you can also provide the name of the application to connect to.</summary>
				public const string connect = "ak.wwise.core.remote.connect";
				/// <summary>Disconnects the Wwise Authoring application from a connected Wwise Sound Engine running executable.</summary>
				public const string disconnect = "ak.wwise.core.remote.disconnect";
				/// <summary>Retrieves all consoles available for connecting Wwise Authoring to a Sound Engine instance.</summary>
				public const string getAvailableConsoles = "ak.wwise.core.remote.getAvailableConsoles";
				/// <summary>Retrieves the connection status.</summary>
				public const string getConnectionStatus = "ak.wwise.core.remote.getConnectionStatus";
			}
			public class undo
			{
				/// <summary>Begins an undo group. Make sure to call \ref ak_wwise_core_undo_endgroup exactly once for every ak.wwise.core.beginUndoGroup call you make. Calls to ak.wwise.core.undo.beginGroup can be nested. When closing a WAMP session, a check is made to ensure that all undo groups are closed. If not, a cancelGroup is called for each of the groups still open.</summary>
				public const string beginGroup = "ak.wwise.core.undo.beginGroup";
				/// <summary>Cancels the last undo group. Please note that this does not revert the operations made since the last \ref ak_wwise_core_undo_begingroup call.</summary>
				public const string cancelGroup = "ak.wwise.core.undo.cancelGroup";
				/// <summary>Ends the last undo group.</summary>
				public const string endGroup = "ak.wwise.core.undo.endGroup";
				/// <summary>Undoes the last operation in the Undo stack.</summary>
				public const string undo_ = "ak.wwise.core.undo.undo";
			}
			public class plugin
			{
				/// <summary>Retrieves the list of all object types registered in Wwise's object model. This function returns the equivalent of \ref wobjects_index .</summary>
				public const string getList = "ak.wwise.core.plugin.getList";
				/// <summary>Retrieves information about an object property. Note that this function does not return the value of a property. To retrieve the value of a property, refer to \ref ak_wwise_core_object_get and \ref waapi_query_return.</summary>
				public const string getProperty = "ak.wwise.core.plugin.getProperty";
				/// <summary>Retrieves the list of property and reference names for an object.</summary>
				public const string getProperties = "ak.wwise.core.plugin.getProperties";
			}
			public class soundbank
			{
				/// <summary>Retrieves a SoundBank's inclusion list.</summary>
				public const string getInclusions = "ak.wwise.core.soundbank.getInclusions";
				/// <summary>Modifies a SoundBank's inclusion list. The 'operation' argument determines how the 'inclusions' argument modifies the SoundBank's inclusion list; 'inclusions' may be added to / removed from / replace the SoundBank's inclusion list.</summary>
				public const string setInclusions = "ak.wwise.core.soundbank.setInclusions";
				/// <summary>Generate a list of SoundBank with import definition defined in the WAAPI request. If you choose to not write the SoundBanks to disk, subscribe to \ref ak_wwise_core_soundbank_generated to get SoundBank structure info and the bank data as base64.</summary>
				public const string generate = "ak.wwise.core.soundbank.generate";
				/// <summary>Imports SoundBank definitions from the specified file. Multiple files can be specified. See the WAAPI log for status messages.</summary>
				public const string processDefinitionFiles = "ak.wwise.core.soundbank.processDefinitionFiles";
				/// <summary>Converts the external sources files for the project as detailed in the wsources file, and places them into either the default folder, or the folder specified by the output argument. External Sources are a special type of source that you can put in a Sound object in Wwise. It indicates that the real sound data will be provided at run time. While External Source conversion is also triggered by SoundBank generation, this operation can be used to process sources not contained in the Wwise Project. Please refer to Wwise SDK help page "Integrating External Sources".</summary>
				public const string convertExternalSources = "ak.wwise.core.soundbank.convertExternalSources";
				/// <summary>Sent when a single SoundBank is generated. This could be sent multiple times during SoundBank generation, for every SoundBank generated and for every platform. To generate SoundBanks, refer to \ref ak_wwise_core_soundbank_generate or \ref ak_wwise_ui_commands_execute with one of the SoundBank generation commands. Refer to \ref globalcommandsids for the list of commands.</summary>
				public const string generated = "ak.wwise.core.soundbank.generated";
				/// <summary>Sent when all SoundBanks are generated.</summary>
				public const string generationDone = "ak.wwise.core.soundbank.generationDone";
			}
			public class sound
			{
				/// <summary>Sets which version of the source is being used for the specified sound. Use \ref ak_wwise_core_object_get with the 'activeSource' return option to get the active source of a sound.</summary>
				public const string setActiveSource = "ak.wwise.core.sound.setActiveSource";
			}
			public class log
			{
				/// <summary>Retrieves the latest log for a specific channel. Refer to \ref ak_wwise_core_log_itemadded to be notified when a item is added to the log.</summary>
				public const string get = "ak.wwise.core.log.get";
				/// <summary>Sent when an item is added to the log. This could be used to retrieve items added to the SoundBank generation log. To retrieve the complete log, refer to \ref ak_wwise_core_log_get.</summary>
				public const string itemAdded = "ak.wwise.core.log.itemAdded";
			}
			public class transport
			{
				/// <summary>Creates a transport object for the given Wwise object. The return transport object can be used to play, stop, pause and resume the Wwise object via the other transport functions.</summary>
				public const string create = "ak.wwise.core.transport.create";
				/// <summary>Prepare the object and its dependencies for playback. Use this function before calling PostEventSync or PostMIDIOnEventSync from IAkGlobalPluginContext.</summary>
				public const string prepare = "ak.wwise.core.transport.prepare";
				/// <summary>Destroys the given transport object.</summary>
				public const string destroy = "ak.wwise.core.transport.destroy";
				/// <summary>Gets the state of the given transport object.</summary>
				public const string getState = "ak.wwise.core.transport.getState";
				/// <summary>Returns the list of transport objects.</summary>
				public const string getList = "ak.wwise.core.transport.getList";
				/// <summary>Executes an action on the given transport object, or all transport objects if none is specified.</summary>
				public const string executeAction = "ak.wwise.core.transport.executeAction";
				/// <summary>Sent when the transport's state has changed.</summary>
				public const string stateChanged = "ak.wwise.core.transport.stateChanged";
			}
			public class audioSourcePeaks
			{
				/// <summary>Gets the min/max peak pairs, in the given region of an audio source, as a collection of binary strings (one per channel). The strings are base-64 encoded, 16-bit signed int arrays, with min and max values being interleaved. If getCrossChannelPeaks is true, only one binary string represents the peaks across all channels globally.</summary>
				public const string getMinMaxPeaksInRegion = "ak.wwise.core.audioSourcePeaks.getMinMaxPeaksInRegion";
				/// <summary>Gets the min/max peak pairs in the entire trimmed region of an audio source, for each channel, as an array of binary strings (one per channel). The strings are base-64 encoded, 16-bit signed int arrays, with min and max values being interleaved. If getCrossChannelPeaks is true, there is only one binary string representing peaks across all channels globally.</summary>
				public const string getMinMaxPeaksInTrimmedRegion = "ak.wwise.core.audioSourcePeaks.getMinMaxPeaksInTrimmedRegion";
			}
			public class profiler
			{
				/// <summary>Retrieves the Audio Objects at a specific profiler capture time.</summary>
				public const string getAudioObjects = "ak.wwise.core.profiler.getAudioObjects";
				/// <summary>Retrieves the game objects at a specific profiler capture time.</summary>
				public const string getGameObjects = "ak.wwise.core.profiler.getGameObjects";
				/// <summary>Retrieves the voices at a specific profiler capture time.</summary>
				public const string getVoices = "ak.wwise.core.profiler.getVoices";
				/// <summary>Retrieves active RTPCs at a specific profiler capture time.</summary>
				public const string getRTPCs = "ak.wwise.core.profiler.getRTPCs";
				/// <summary>Retrieves the busses at a specific profiler capture time.</summary>
				public const string getBusses = "ak.wwise.core.profiler.getBusses";
				/// <summary>Retrieves all parameters affecting voice volume, highpass and lowpass for a voice path, resolved from pipeline IDs.</summary>
				public const string getVoiceContributions = "ak.wwise.core.profiler.getVoiceContributions";
				/// <summary>Specifies the type of data you want to capture. Overrides the user's profiler settings.</summary>
				public const string enableProfilerData = "ak.wwise.core.profiler.enableProfilerData";
				/// <summary>Returns the current time of the specified profiler cursor, in milliseconds.</summary>
				public const string getCursorTime = "ak.wwise.core.profiler.getCursorTime";
				/// <summary>Starts the profiler capture and returns the time at the beginning of the capture, in milliseconds.</summary>
				public const string startCapture = "ak.wwise.core.profiler.startCapture";
				/// <summary>Stops the profiler capture and returns the time at the end of the capture, in milliseconds.</summary>
				public const string stopCapture = "ak.wwise.core.profiler.stopCapture";
				public class captureLog
				{
					/// <summary>Sent when a new entry is added to the capture log. Note that all entries are being sent. No filtering is applied as opposed to the Capture Log view.</summary>
					public const string itemAdded = "ak.wwise.core.profiler.captureLog.itemAdded";
				}
				/// <summary>Sent when a game object has been registered.</summary>
				public const string gameObjectRegistered = "ak.wwise.core.profiler.gameObjectRegistered";
				/// <summary>Sent when a game object has been unregistered.</summary>
				public const string gameObjectUnregistered = "ak.wwise.core.profiler.gameObjectUnregistered";
				/// <summary>Sent when the game objects have been reset, such as closing a connection to a game while profiling.</summary>
				public const string gameObjectReset = "ak.wwise.core.profiler.gameObjectReset";
				/// <summary>Sent when a state group state has been changed. This subscription does not require the profiler capture log to be started.</summary>
				public const string stateChanged = "ak.wwise.core.profiler.stateChanged";
				/// <summary>Sent when a switch group state has been changed. This function does not require the profiler capture log to be started.</summary>
				public const string switchChanged = "ak.wwise.core.profiler.switchChanged";
			}
		}
		public class ui
		{
			/// <summary>Bring Wwise main window to foreground. Refer to SetForegroundWindow and AllowSetForegroundWindow on MSDN for more information on the restrictions. Refer to ak.wwise.core.getInfo to obtain the Wwise process ID for AllowSetForegroundWindow.</summary>
			public const string bringToForeground = "ak.wwise.ui.bringToForeground";
			public class project
			{
				/// <summary>Opens a project, specified by path. Please refer to \ref ak_wwise_core_project_loaded for further explanations on how to be notified when the operation has completed.</summary>
				public const string open = "ak.wwise.ui.project.open";
				/// <summary>Closes the current project.</summary>
				public const string close = "ak.wwise.ui.project.close";
			}
			public class commands
			{
				/// <summary>Executes a command. Some commands can take a list of objects as parameters. Refer to \ref globalcommandsids for the available commands.</summary>
				public const string execute = "ak.wwise.ui.commands.execute";
				/// <summary>Gets the list of commands.</summary>
				public const string getCommands = "ak.wwise.ui.commands.getCommands";
				/// <summary>Registers an array of add-on commands. Registered commands remain until the Wwise process is terminated. Refer to \ref defining_custom_commands for more information about registering commands. Also refer to \ref ak_wwise_ui_commands_executed.</summary>
				public const string register = "ak.wwise.ui.commands.register";
				/// <summary>Unregisters an array of add-on UI commands.</summary>
				public const string unregister = "ak.wwise.ui.commands.unregister";
				/// <summary>Sent when a command is executed. The objects for which the command is executed are sent in the publication.</summary>
				public const string executed = "ak.wwise.ui.commands.executed";
			}
			/// <summary>Retrieves the list of objects currently selected by the user in the active view.</summary>
			public const string getSelectedObjects = "ak.wwise.ui.getSelectedObjects";
			/// <summary>Captures a part of the Wwise UI relative to a view.</summary>
			public const string captureScreen = "ak.wwise.ui.captureScreen";
			/// <summary>Sent when the selection changes in the project.</summary>
			public const string selectionChanged = "ak.wwise.ui.selectionChanged";
		}
		public class waapi
		{
			/// <summary>Retrieves the list of topics to which a client can subscribe.</summary>
			public const string getTopics = "ak.wwise.waapi.getTopics";
			/// <summary>Retrieves the list of functions.</summary>
			public const string getFunctions = "ak.wwise.waapi.getFunctions";
			/// <summary>Retrieves the JSON schema of a Waapi URI.</summary>
			public const string getSchema = "ak.wwise.waapi.getSchema";
		}
		public class debug
		{
			/// <summary>Enables debug assertions. Every call to enableAsserts with 'false' increments the ref count. Calling with true decrements the ref count. This is only available with Debug builds.</summary>
			public const string enableAsserts = "ak.wwise.debug.enableAsserts";
			/// <summary>Private use only.</summary>
			public const string testAssert = "ak.wwise.debug.testAssert";
			/// <summary>Private use only.</summary>
			public const string testCrash = "ak.wwise.debug.testCrash";
			/// <summary>Enables or disables the automation mode for Wwise. This reduces the potential interruptions caused by message boxes and dialogs. For instance, enabling the automation mode silently accepts: project migration, project load log, EULA acceptance, project licence display and generic message boxes.</summary>
			public const string enableAutomationMode = "ak.wwise.debug.enableAutomationMode";
			/// <summary>Sent when an assert has failed. This is only available in Debug builds.</summary>
			public const string assertFailed = "ak.wwise.debug.assertFailed";
		}
		public class cli
		{
			/// <summary>Migrate and save the project.</summary>
			public const string migrate = "ak.wwise.cli.migrate";
			/// <summary>Load the project and do nothing else. This is useful to see the log for verification purposes without actually migrating and saving.</summary>
			public const string verify = "ak.wwise.cli.verify";
			/// <summary>Imports a tab-delimited file to create and modify different object hierarchies. The project is automatically migrated (if required). It is also automatically saved following the import.</summary>
			public const string tabDelimitedImport = "ak.wwise.cli.tabDelimitedImport";
			/// <summary>Starts a command-line Wwise Authoring API server, to which client applications, using the Wwise Authoring API, can connect.</summary>
			public const string waapiServer = "ak.wwise.cli.waapiServer";
			/// <summary>Creates a blank new project. The project must not already exist. If the folder does not exist, it is created.</summary>
			public const string createNewProject = "ak.wwise.cli.createNewProject";
			/// <summary>Dump the objects model of a project as a JSON file.</summary>
			public const string dumpObjects = "ak.wwise.cli.dumpObjects";
			/// <summary>Adds a new platform to a project. The platform must not already exist.</summary>
			public const string addNewPlatform = "ak.wwise.cli.addNewPlatform";
			/// <summary>External Sources conversion. Converts the external sources files for the specified project. Optionally, additional WSOURCES can be specified. External Sources are a special type of source that you can put in a Sound object in Wwise. It indicates that the real sound data will be provided at run time. While External Source conversion is also triggered by SoundBank generation, this operation can be used to process sources not contained in the Wwise Project. Please refer to \ref integrating_external_sources.</summary>
			public const string convertExternalSource = "ak.wwise.cli.convertExternalSource";
			/// <summary>SoundBank generation. SoundBank generation is performed according to the settings stored in the project. User SoundBanks Settings are normally ignored when SoundBank generation is launched from the command line. However, when using the Source Control for generated SoundBanks, the User Project Settings will be loaded for the Source Control settings. Also, some of these settings can be overridden from the command line.</summary>
			public const string generateSoundbank = "ak.wwise.cli.generateSoundbank";
			/// <summary>Moves the project's media IDs from its work units (.wwu) to a single file, <project-name>.mediaid.  This command will force a save of all the project's work units.</summary>
			public const string moveMediaIdsToSingleFile = "ak.wwise.cli.moveMediaIdsToSingleFile";
			/// <summary>Moves the project's media IDs from a single xml file <project-name>.mediaid to its work units (.wwu).  This command will force a save of all the project's work units.</summary>
			public const string moveMediaIdsToWorkUnits = "ak.wwise.cli.moveMediaIdsToWorkUnits";
			/// <summary>Loads the project and updates the contents of <project-name>.mediaid, if it exists.</summary>
			public const string updateMediaIdsInSingleFile = "ak.wwise.cli.updateMediaIdsInSingleFile";
		}
	}
	public class soundengine
	{
		/// <summary>Asynchronously post an Event to the sound engine (by event ID). See <tt>AK::SoundEngine::PostEvent</tt>.</summary>
		public const string postEvent = "ak.soundengine.postEvent";
		/// <summary>Executes an action on all nodes that are referenced in the specified event in a Play action. See <tt>AK::SoundEngine::ExecuteActionOnEvent</tt>.</summary>
		public const string executeActionOnEvent = "ak.soundengine.executeActionOnEvent";
		/// <summary>Register a game object. Registering a game object twice does nothing. Unregistering it once unregisters it no matter how many times it has been registered. See <tt>AK::SoundEngine::RegisterGameObj</tt>.</summary>
		public const string registerGameObj = "ak.soundengine.registerGameObj";
		/// <summary>Stops the current content, associated to the specified playing ID, from playing. See <tt>AK::SoundEngine::StopPlayingID</tt>.</summary>
		public const string stopPlayingID = "ak.soundengine.stopPlayingID";
		/// <summary>Stop playing the current content associated to the specified game object ID. If no game object is specified, all sounds are stopped. See <tt>AK::SoundEngine::StopAll</tt>.</summary>
		public const string stopAll = "ak.soundengine.stopAll";
		/// <summary>Display a message in the Profiler's Capture Log view.</summary>
		public const string postMsgMonitor = "ak.soundengine.postMsgMonitor";
		/// <summary>Set a game object's obstruction and occlusion levels. This function is used to affect how an object should be heard by a specific listener. See <tt>AK::SoundEngine::SetObjectObstructionAndOcclusion</tt>.</summary>
		public const string setObjectObstructionAndOcclusion = "ak.soundengine.setObjectObstructionAndOcclusion";
		/// <summary>Set the output bus volume (direct) to be used for the specified game object. See <tt>AK::SoundEngine::SetGameObjectOutputBusVolume</tt>.</summary>
		public const string setGameObjectOutputBusVolume = "ak.soundengine.setGameObjectOutputBusVolume";
		/// <summary>Sets the Auxiliary Busses to route the specified game object. See <tt>AK::SoundEngine::SetGameObjectAuxSendValues</tt>.</summary>
		public const string setGameObjectAuxSendValues = "ak.soundengine.setGameObjectAuxSendValues";
		/// <summary>Posts the specified Trigger. See <tt>AK::SoundEngine::PostTrigger</tt>.</summary>
		public const string postTrigger = "ak.soundengine.postTrigger";
		/// <summary>Sets the State of a Switch Group. See <tt>AK::SoundEngine::SetSwitch</tt>.</summary>
		public const string setSwitch = "ak.soundengine.setSwitch";
		/// <summary>Gets the current state of a Switch Group for a given Game Object.</summary>
		public const string getSwitch = "ak.soundengine.getSwitch";
		/// <summary>Sets the State of a State Group. See <tt>AK::SoundEngine::SetState</tt>.</summary>
		public const string setState = "ak.soundengine.setState";
		/// <summary>Gets the current state of a State Group. When using setState just prior to getState, allow a brief delay (no more than 10ms) for the information to update in the sound engine.</summary>
		public const string getState = "ak.soundengine.getState";
		/// <summary>Resets the value of a real-time parameter control to its default value, as specified in the Wwise project. See <tt>AK::SoundEngine::ResetRTPCValue</tt>.</summary>
		public const string resetRTPCValue = "ak.soundengine.resetRTPCValue";
		/// <summary>Sets the value of a real-time parameter control. See <tt>AK::SoundEngine::SetRTPCValue</tt>.</summary>
		public const string setRTPCValue = "ak.soundengine.setRTPCValue";
		/// <summary>Sets a listener's spatialization parameters. This lets you define listener-specific volume offsets for each audio channel. See <tt>AK::SoundEngine::SetListenerSpatialization</tt>.</summary>
		public const string setListenerSpatialization = "ak.soundengine.setListenerSpatialization";
		/// <summary>Sets multiple positions for a single game object. Setting multiple positions for a single game object is a way to simulate multiple emission sources while using the resources of only one voice. This can be used to simulate wall openings, area sounds, or multiple objects emitting the same sound in the same area. See <tt>AK::SoundEngine::SetMultiplePositions</tt>.</summary>
		public const string setMultiplePositions = "ak.soundengine.setMultiplePositions";
		/// <summary>Sets the position of a game object. See <tt>AK::SoundEngine::SetPosition</tt>.</summary>
		public const string setPosition = "ak.soundengine.setPosition";
		/// <summary>Sets the scaling factor of a game object. You can modify the attenuation computations on this game object to simulate sounds with a larger or smaller affected areas. See <tt>AK::SoundEngine::SetScalingFactor</tt>.</summary>
		public const string setScalingFactor = "ak.soundengine.setScalingFactor";
		/// <summary>Sets the default active listeners for all subsequent game objects that are registered. See <tt>AK::SoundEngine::SetDefaultListeners</tt>.</summary>
		public const string setDefaultListeners = "ak.soundengine.setDefaultListeners";
		/// <summary>Sets a single game object's active listeners. By default, all new game objects have no listeners active, but this behavior can be overridden with <tt>SetDefaultListeners()</tt>. Inactive listeners are not computed. See <tt>AK::SoundEngine::SetListeners</tt>.</summary>
		public const string setListeners = "ak.soundengine.setListeners";
		/// <summary>Seeks inside all playing objects that are referenced in Play Actions of the specified Event. See <tt>AK::SoundEngine::SeekOnEvent</tt>.</summary>
		public const string seekOnEvent = "ak.soundengine.seekOnEvent";
		/// <summary>Unregisters a game object. Registering a game object twice does nothing. Unregistering it once unregisters it no matter how many times it has been registered. Unregistering a game object while it is in use is allowed, but the control over the parameters of this game object is lost. For example, say a sound associated with this game object is a 3D moving sound. It stops moving when the game object is unregistered, and there is no way to regain control over the game object. See <tt>AK::SoundEngine::UnregisterGameObj</tt>.</summary>
		public const string unregisterGameObj = "ak.soundengine.unregisterGameObj";
	}
}
