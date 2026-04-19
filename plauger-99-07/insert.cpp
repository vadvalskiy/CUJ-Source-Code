   _Pairib insert(const value_type& _V)
      {_Nodeptr _X = _Root();
      _Nodeptr _Y = _Head;
      bool _Addleft = true;
      while (!_Isnil(_X))
         {_Y = _X;
         _Addleft = comp(_Kfn()(_V), _Key(_X));
         _X = _Addleft ? _Left(_X) : _Right(_X); }
      if (_Multi)
         return (_Pairib(_Insert(_Addleft, _Y, _V), true));
      else
         {iterator _P = iterator(_Y);
         if (!_Addleft)
            ;
         else if (_P == begin())
            return (_Pairib(_Insert(true, _Y, _V), true));
         else
            --_P;
         if (comp(_Key(_P._Mynode()), _Kfn()(_V)))
            return (_Pairib(_Insert(_Addleft, _Y, _V), true));
         else
            return (_Pairib(_P, false)); }}
