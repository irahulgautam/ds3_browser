/*
 * *****************************************************************************
 *   Copyright 2014 Spectra Logic Corporation. All Rights Reserved.
 *   Licensed under the Apache License, Version 2.0 (the "License"). You may not
 *   use this file except in compliance with the License. A copy of the License
 *   is located at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *   or in the "license" file accompanying this file.
 *   This file is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 *   CONDITIONS OF ANY KIND, either express or implied. See the License for the
 *   specific language governing permissions and limitations under the License.
 * *****************************************************************************
 */

#ifndef BUCKET_H
#define BUCKET_H

#include <QAbstractItemModel>
#include <ds3.h>

class Bucket : public QAbstractItemModel
{
	Q_OBJECT

public:
	Bucket(ds3_get_service_response* response, QObject* parent = 0);
	~Bucket();

	QModelIndex index(int row, int column = 0,
			  const QModelIndex &parent = QModelIndex()) const;

	QModelIndex parent(const QModelIndex &index) const;

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index,
		int role = Qt::DisplayRole) const;

	QVariant headerData(int section, Qt::Orientation orientation,
		int role = Qt::DisplayRole) const;

	bool hasChildren(const QModelIndex & parent = QModelIndex()) const;

private:
	ds3_get_service_response* m_get_service_response;

	// Must match COLUMN_NAMES
	enum Column { NAME, OWNER, CREATED, COUNT };
	static const char* const COLUMN_NAMES[];
};

#endif
