/*****************************************************************************
 * PokerTH - The open source texas holdem engine                             *
 * Copyright (C) 2006-2012 Felix Hammer, Florian Thauer, Lothar May          *
 *                                                                           *
 * This program is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU Affero General Public License as            *
 * published by the Free Software Foundation, either version 3 of the        *
 * License, or (at your option) any later version.                           *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU Affero General Public License for more details.                       *
 *                                                                           *
 * You should have received a copy of the GNU Affero General Public License  *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *                                                                           *
 *                                                                           *
 * Additional permission under GNU AGPL version 3 section 7                  *
 *                                                                           *
 * If you modify this program, or any covered work, by linking or            *
 * combining it with the OpenSSL project's OpenSSL library (or a             *
 * modified version of that library), containing parts covered by the        *
 * terms of the OpenSSL or SSLeay licenses, the authors of PokerTH           *
 * (Felix Hammer, Florian Thauer, Lothar May) grant you additional           *
 * permission to convey the resulting work.                                  *
 * Corresponding Source for a non-source form of such a combination          *
 * shall include the source code for the parts of OpenSSL used as well       *
 * as that of the covered work.                                              *
 *****************************************************************************/
#ifndef CLEANERCONFIG_H
#define CLEANERCONFIG_H

#include <vector>
#include <string>
#include <list>

enum ConfigState { NONEXISTING, OLD };
enum ConfigType { CONFIG_TYPE_INT, CONFIG_TYPE_STRING, CONFIG_TYPE_INT_LIST, CONFIG_TYPE_STRING_LIST };


class CleanerConfig
{
public:
	CleanerConfig();

	~CleanerConfig();

	std::string getConfigFileName() const {
		return configFileName;
	}

	void fillBuffer();
	void writeBuffer() const;

	void updateConfig(ConfigState);

	int readConfigInt(std::string varName) const;
	std::string readConfigString(std::string varName) const;
	std::list<int> readConfigIntList(std::string varName) const;
	std::list<std::string> readConfigStringList(std::string varName) const;

	void writeConfigInt(std::string varName, int varCont);
	void writeConfigString(std::string varName, std::string varCont);
	void writeConfigIntList(std::string varName, std::list<int> varCont);
	void writeConfigStringList(std::string varName, std::list<std::string> varCont);

	std::string stringToUtf8(const std::string & );
	std::string stringFromUtf8(const std::string &);
	std::string getDefaultLanguage();

private:

	struct ConfigInfo {
		ConfigInfo(const std::string &n, ConfigType t, const std::string &d, const std::list<std::string> &l =std::list<std::string>()) : name(n), type(t), defaultValue(d), defaultListValue(l) {}
		std::string name;
		ConfigType type;
		std::string defaultValue;
		std::list<std::string> defaultListValue;

	};

	std::vector<ConfigInfo> configList;
	std::vector<ConfigInfo> configBufferList;

	std::string configFileName;
	std::string logDir;
	std::string dataDir;
	std::string cacheDir;
	int configRev;

	ConfigState myConfigState;

};

#endif
