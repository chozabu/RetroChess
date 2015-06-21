/****************************************************************
 *  RetroShare is distributed under the following license:
 *
 *  Copyright (C) 2015
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/
#include <retroshare/rsplugin.h>
#include <retroshare/rsversion.h>
#include <retroshare-gui/RsAutoUpdatePage.h>
#include <QTranslator>
#include <QApplication>
#include <QString>
#include <QIcon>
#include <QMessageBox>

#include "NetExamplePlugin.h"
#include "interface/rsNetExample.h"
#include "gui/NEMainpage.h"
#include "gui/NetExampleNotify.h"


#define IMAGE_NetExample ":/images/talking_on.svg"

static void *inited = new NetExamplePlugin() ;

extern "C" {

	// This is *the* functions required by RS plugin system to give RS access to the plugin.
	// Be careful to:
	// - always respect the C linkage convention
	// - always return an object of type RsPlugin*
	//
	void *RETROSHARE_PLUGIN_provide()
	{
		static NetExamplePlugin *p = new NetExamplePlugin() ;

		return (void*)p ;
	}

	// This symbol contains the svn revision number grabbed from the executable. 
	// It will be tested by RS to load the plugin automatically, since it is safe to load plugins
	// with same revision numbers, assuming that the revision numbers are up-to-date.
	//
	uint32_t RETROSHARE_PLUGIN_revision = RS_REVISION_NUMBER ;

	// This symbol contains the svn revision number grabbed from the executable. 
	// It will be tested by RS to load the plugin automatically, since it is safe to load plugins
	// with same revision numbers, assuming that the revision numbers are up-to-date.
	//
	uint32_t RETROSHARE_PLUGIN_api = RS_PLUGIN_API_VERSION ;
}

void NetExamplePlugin::getPluginVersion(int& major, int& minor, int& build, int& svn_rev) const
{
	major = RS_MAJOR_VERSION ;
	minor = RS_MINOR_VERSION ;
	build = RS_BUILD_NUMBER ;
	svn_rev = RS_REVISION_NUMBER ;
}

NetExamplePlugin::NetExamplePlugin()
{
	qRegisterMetaType<RsPeerId>("RsPeerId");
	mainpage = NULL ;
	mNetExample = NULL ;
	mPlugInHandler = NULL;
	mPeers = NULL;
	config_page = NULL ;
	mIcon = NULL ;

	mNetExampleNotify = new NetExampleNotify;
}

void NetExamplePlugin::setInterfaces(RsPlugInInterfaces &interfaces)
{
    mPeers = interfaces.mPeers;
}

/*ConfigPage *NetExamplePlugin::qt_config_page() const
{
	// The config pages are deleted when config is closed, so it's important not to static the
	// created object.
	//
	return new AudioInputConfig() ;
}*/

QDialog *NetExamplePlugin::qt_about_page() const
{
	static QMessageBox *about_dialog = NULL ;
	
	if(about_dialog == NULL)
	{
		about_dialog = new QMessageBox() ;

		QString text ;
		text += QObject::tr("<h3>RetroShare NetExample plugin</h3><br/>   * Contributors: Cyril Soler, Josselin Jacquard<br/>") ;
		text += QObject::tr("<br/>The NetExample plugin adds NetExample to the private chat window of RetroShare. to use it, proceed as follows:<UL>") ;
		text += QObject::tr("<li> setup microphone levels using the configuration panel</li>") ;
		text += QObject::tr("<li> check your microphone by looking at the VU-metters</li>") ;
		text += QObject::tr("<li> in the private chat, enable sound input/output by clicking on the two NetExample icons</li></ul>") ;
		text += QObject::tr("Your friend needs to run the plugin to talk/listen to you, or course.") ;
		text += QObject::tr("<br/><br/>This is an experimental feature. Don't hesitate to send comments and suggestion to the RS dev team.") ;

		about_dialog->setText(text) ;
		about_dialog->setStandardButtons(QMessageBox::Ok) ;
	}

	return about_dialog ;
}

/*ChatWidgetHolder *NetExamplePlugin::qt_get_chat_widget_holder(ChatWidget *chatWidget) const
{
	switch (chatWidget->chatType()) {
	case ChatWidget::CHATTYPE_PRIVATE:
		return new NetExampleChatWidgetHolder(chatWidget, mNetExampleNotify);
	case ChatWidget::CHATTYPE_UNKNOWN:
	case ChatWidget::CHATTYPE_LOBBY:
	case ChatWidget::CHATTYPE_DISTANT:
		break;
	}

	return NULL;
}*/

p3Service *NetExamplePlugin::p3_service() const
{
	if(mNetExample == NULL)
		rsNetExample = mNetExample = new p3NetExample(mPlugInHandler,mNetExampleNotify) ; // , 3600 * 24 * 30 * 6); // 6 Months

	return mNetExample ;
}

void NetExamplePlugin::setPlugInHandler(RsPluginHandler *pgHandler)
{
    mPlugInHandler = pgHandler;
}

QIcon *NetExamplePlugin::qt_icon() const
{
	if (mIcon == NULL) {
		Q_INIT_RESOURCE(NetExample_images);

		mIcon = new QIcon(IMAGE_NetExample);
	}

	return mIcon;
}
MainPage *NetExamplePlugin::qt_page() const
{
	if(mainpage == NULL){
		mainpage = new NEMainpage(0, mNetExampleNotify);//mPeers, mFiles) ;
		//tpage = new NEMainpage( );
		//mainpage = tpage;
	}

	return mainpage ;
}

std::string NetExamplePlugin::getShortPluginDescription() const
{
	return "NetExample";
}

std::string NetExamplePlugin::getPluginName() const
{
	return "NetExamplePlugin";
}

QTranslator* NetExamplePlugin::qt_translator(QApplication */*app*/, const QString& languageCode, const QString& externalDir) const
{
	return NULL;
}

void NetExamplePlugin::qt_sound_events(SoundEvents &/*events*/) const
{
//	events.addEvent(QApplication::translate("NetExample", "NetExample"), QApplication::translate("NetExample", "Incoming call"), NetExample_SOUND_INCOMING_CALL);
}

/*ToasterNotify *NetExamplePlugin::qt_toasterNotify(){
	if (!mNetExampleToasterNotify) {
		mNetExampleToasterNotify = new NetExampleToasterNotify(mNetExample, mNetExampleNotify);
	}
	return mNetExampleToasterNotify;
}*/
