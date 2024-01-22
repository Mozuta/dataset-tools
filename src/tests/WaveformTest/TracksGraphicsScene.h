//
// Created by fluty on 2023/11/14.
//

#ifndef DATASET_TOOLS_TRACKSGRAPHICSSCENE_H
#define DATASET_TOOLS_TRACKSGRAPHICSSCENE_H

#include <QGraphicsScene>


class TracksGraphicsScene : public QGraphicsScene{
public:
    explicit TracksGraphicsScene();
    ~TracksGraphicsScene() override = default;

public slots:
    void setScale(qreal sx, qreal sy);

public:
//    void setViewportRect(const QRectF &rect);
protected:
    int m_sceneWidth = 1920 / 480 * 64 * 100; // 100 bars
    int m_sceneHeight = 2000;
};



#endif // DATASET_TOOLS_TRACKSGRAPHICSSCENE_H
