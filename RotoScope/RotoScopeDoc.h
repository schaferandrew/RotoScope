/*! \file RotoScopeDoc.h
 *
 * Header file for the RotoScope document class
 * \author Charles B. Owen
 */

#pragma once

#include <vector>
#include <list>
#include <stack>

#include "video/MovieSource.h"
#include "video/MovieMake.h"
#include "audio/DirSoundSource.h"
#include "graphics/GrImage.h"
#include "LineDlg.h"

/*! \mainpage RotoScope Starter Application
 *
 * The Rotoscope application is a simple program that allows you to 
 * load frames of video, modify them in interesting ways, and save 
 * them to a new video file. Rotoscoping is an animation technique where 
 * frames of a movie are advanced one by one and edited by a user. 
 */

//! Rotoscope document class 
/*! RotoScope document class */
class CRotoScopeDoc : public CDocument
{
public:
	CRotoScopeDoc();
	virtual ~CRotoScopeDoc();
	DECLARE_DYNCREATE(CRotoScopeDoc)

	virtual BOOL OnNewDocument();
    void Mouse(int p_x, int p_y);

    /*! Get the image we are editing 
     * \returns Constant pointer to image we are editing */
    const CGrImage &GetImage() const {return m_image;}

// Implementation
public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
    afx_msg void OnMoviesOpensourcemovie();
    afx_msg void OnMoviesOpenoutputmovie();
    afx_msg void OnFramesCreateoneframe();

    void CreateOneFrame();

    CMovieSource        m_moviesource;      // Any source movie
    CMovieMake          m_moviemake;        // Any movie we are outputing to
    CDirSoundSource     m_backaudio;        // Any background audio?

    CGrImage            m_image;            // Current image being displayed
    std::vector<short>  m_audio;            // Current audio to be written to the output
	int					m_movieframe;       // Movie frame we are writing
	std::vector<std::list<CPoint> >     m_draw;
	CGrImage			m_initial;
	CLineDlg			m_dlg;
	CGrImage			m_bird;
	CGrImage	m_background;
	CGrImage	m_flame;

	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
	int m_b;
	int m_g;
	int m_r;
	int m_width;
	int m_theta;

	int m_mode;
	int m_backgroundMode;
	int m_dot_count;
	double tolerance = 0.20;
	int m_colorR = 0;
	int m_colorG = 0;
	int m_colorB = 0;
	int m_mouseMode = 0;
	int m_flameScale = 5;
	int m_flameAngle = 0;

	std::stack<CGrImage>	m_images;

    afx_msg void OnFramesWriteoneframe();
    afx_msg void OnUpdateFramesWriteoneframe(CCmdUI *pCmdUI);
    afx_msg void OnMoviesClosesourcemovie();
    afx_msg void OnUpdateMoviesClosesourcemovie(CCmdUI *pCmdUI);
    afx_msg void OnMoviesCloseoutputmovie();
    afx_msg void OnUpdateMoviesCloseoutputmovie(CCmdUI *pCmdUI);
    afx_msg void OnFramesWritethencreateoneframe();
    afx_msg void OnUpdateFramesWritethencreateoneframe(CCmdUI *pCmdUI);
    afx_msg void OnFramesWritethencreateonesecond();
    void MessagePump(void);
    afx_msg void OnFramesWritethencreateremaining();
    afx_msg void OnMoviesOpenbackgroundaudio();
    afx_msg void OnMoviesClosebackgroundaudio();
    afx_msg void OnUpdateMoviesClosebackgroundaudio(CCmdUI *pCmdUI);
public:
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	void SaveMovieData(IXMLDOMDocument *xmlDoc, IXMLDOMNode *inNode);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	void XmlLoadMovie(IXMLDOMNode *xml);
	void XmlLoadFrame(IXMLDOMNode *xml);
	afx_msg void OnEditClearframe();
	void DrawImage();
	void DrawLine(CGrImage &image, int x1, int y1, int x2, int y2, int width, int b, int g, int r);
	afx_msg void OnEditDrawline();
	afx_msg void OnEditPlacebird();
	void DrawBird(CGrImage &image, int x1, int y1);
	void DrawFlame(CGrImage &image, int x1, int y1);
	void RotateImage(CGrImage &image, int theta);
	afx_msg void OnEditRotateimage();
	afx_msg void OnEditSetvariables();
	afx_msg void OnMousemodePen();
	afx_msg void OnMousemodeLine();
	afx_msg void OnMousemodeBird();
	afx_msg void OnEditUndo32793();
	afx_msg void OnChromakeyBlack();
	afx_msg void OnChromakeyStreet();
	void PaintLine(CGrImage &image, int x1, int y1, int x2, int y2);
	CGrImage RotateObject(CGrImage &image, int theta);
	afx_msg void OnMousemodeBrush();
	afx_msg void OnEditWhitebrush();
	afx_msg void OnEditRedbrush();
	afx_msg void OnEditBluebrush();
	afx_msg void OnMousemodeFlame();
	afx_msg void OnFlamecontrolsAdvanceflame();
};


