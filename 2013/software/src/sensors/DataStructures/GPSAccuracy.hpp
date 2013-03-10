#ifndef GPSACCURACY_H
#define GPSACCURACY_H

class GPSAccuracy
{
    public:
        inline GPSAccuracy(): _LatVariance(0), _LongVariance(0),
         _HeadingVariance(0), _SpeedVariance(0)
        {

        }

        inline GPSAccuracy(double latVar, double longVar, double headingVar, double speedVar) : _LatVariance(latVar), _LongVariance(longVar),
         _HeadingVariance(headingVar), _SpeedVariance(speedVar)
         {
         }

         inline double LatVar(void)
         {
            return _LatVariance;
         }


         inline double LongVar(void)
         {
             return _LongVariance;
         }

         inline double HeadingVar()
         {
             return _HeadingVariance;
         }

        inline double SpeedVar(void)
         {
            return _SpeedVariance;
         }

         inline void ScaleUncertainty(double scale)
         {
             _LatVariance*=scale;
             _LongVariance*=scale;
            _HeadingVariance*=scale;
            _SpeedVariance*=scale;
         }

        inline void LatVar(double newVar)
        {
            _LatVariance = newVar;
        }

        inline void LongVar(double newVar)
        {
            _LongVariance = newVar;
        }

        inline void HeadingVar(double newVar)
        {
            _HeadingVariance = newVar;
        }

        inline void SpeedVar(double newVar)
        {
            _SpeedVariance = newVar;
        }

    private:
        double _LatVariance;
        double _LongVariance;
        double _HeadingVariance;
        double _SpeedVariance;
};

#endif // GPSACCURACY_H