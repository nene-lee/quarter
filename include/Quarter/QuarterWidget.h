#ifndef QUARTER_QUARTERWIDGET_H
#define QUARTER_QUARTERWIDGET_H

/**************************************************************************\
 *
 *  This file is part of the SIM Quarter extension library for Coin.
 *  Copyright (C) 1998-2007 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License ("GPL") version 2
 *  as published by the Free Software Foundation.  See the file COPYING
 *  at the root directory of this source distribution for additional
 *  information about the GNU GPL.
 *
 *  For using SIM Quarter with software that can not be combined with
 *  the GNU GPL, and for taking advantage of the additional benefits of
 *  our support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion AS, Bygd�y all� 5, N-0257 Oslo, NORWAY. (www.sim.no)
 *
\**************************************************************************/

#include <QtOpenGL/QGLWidget>
#include <Inventor/SbBasic.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Quarter/Basic.h>
#include <QtGui/QColor>

class QMenu;
class SoNode;
class SoEvent;
class SoCamera;
class SoEventManager;
class SoRenderManager;
class SoDirectionalLight;

namespace SIM { namespace Coin3D { namespace Quarter {

class EventManager;
class DeviceManager;

class QUARTER_DLL_API QuarterWidget : public QGLWidget {
  typedef QGLWidget inherited;
  Q_OBJECT
  Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor)
  Q_PROPERTY(bool contextMenuEnabled READ contextMenuEnabled WRITE enableContextMenu)

public:
  QuarterWidget(QWidget * parent = 0, const QGLWidget * sharewidget = 0, Qt::WindowFlags f = 0);
  QuarterWidget(QGLContext * context, QWidget * parent = 0, const QGLWidget * sharewidget = 0, Qt::WindowFlags f = 0);
  virtual ~QuarterWidget();

  void setStateCursor(const SbName & state, const QCursor & cursor);
  void enableHeadlight(const SbBool onoff);
  SoDirectionalLight * getHeadlight(void);
  uint32_t getCacheContextId(void) const;

  void setTransparencyType(SoGLRenderAction::TransparencyType type);
  void setBackgroundColor(const QColor & color);
  QColor getBackgroundColor(void) const;
  QMenu * getContextMenu(void) const;
  void enableContextMenu(bool yes);
  bool contextMenuEnabled(void) const;

  virtual void setSceneGraph(SoNode * root);
  virtual SoNode * getSceneGraph(void) const;
  
  DeviceManager * getDeviceManager(void) const;
  EventManager * getEventManager(void) const;
  SoEventManager * getSoEventManager(void) const;
  SoRenderManager * getSoRenderManager(void) const;

public slots:
  virtual void viewAll(void);

protected:
  virtual void resizeGL(int width, int height);
  virtual void initializeGL(void);
  virtual void paintGL(void);
  virtual bool event(QEvent * event);
  virtual void actualRedraw(void);

  static void renderCB(void * closure, SoRenderManager *);

private:
  void constructor(const QGLWidget * sharewidget);
  friend class QuarterWidgetP;
  class QuarterWidgetP * pimpl;
};

}}} // namespace

#endif // QUARTER_QUARTERWIDGET_H
