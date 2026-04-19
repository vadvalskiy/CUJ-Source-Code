   iterator _Insert(bool _Addleft, _Nodeptr _Y,
      const value_type& _V)
      {if (max_size() - 1 <= _Size)
         _THROW(length_error, "map/set<T> too long");
      _Nodeptr _Z = _Buynode(_Y, _Red);
      _Left(_Z) = _Head, _Right(_Z) = _Head;
      try
         {_Consval(&_Value(_Z), _V); }
      catch
         {_Freenode(_Z);
         throw; }
      ++_Size;
      if (_Y == _Head)
         {_Root() = _Z;
         _Lmost() = _Z, _Rmost() = _Z; }
      else if (_Addleft)
         {_Left(_Y) = _Z;
         if (_Y == _Lmost())
            _Lmost() = _Z; }
      else
         {_Right(_Y) = _Z;
         if (_Y == _Rmost())
            _Rmost() = _Z; }

   // REBALANCE AND RECOLOR
      for (_Nodeptr _X = _Z; _Color(_Parent(_X)) == _Red; )
         if (_Parent(_X) == _Left(_Parent(_Parent(_X))))
            {_Y = _Right(_Parent(_Parent(_X)));
            if (_Color(_Y) == _Red)
               {_Color(_Parent(_X)) = _Black;
               _Color(_Y) = _Black;
               _Color(_Parent(_Parent(_X))) = _Red;
               _X = _Parent(_Parent(_X)); }
            else
               {if (_X == _Right(_Parent(_X)))
                  {_X = _Parent(_X);
                  _Lrotate(_X); }
               _Color(_Parent(_X)) = _Black;
               _Color(_Parent(_Parent(_X))) = _Red;
               _Rrotate(_Parent(_Parent(_X))); }}
         else
            {_Y = _Left(_Parent(_Parent(_X)));
            if (_Color(_Y) == _Red)
               {_Color(_Parent(_X)) = _Black;
               _Color(_Y) = _Black;
               _Color(_Parent(_Parent(_X))) = _Red;
               _X = _Parent(_Parent(_X)); }
            else
               {if (_X == _Left(_Parent(_X)))
                  {_X = _Parent(_X);
                  _Rrotate(_X); }
               _Color(_Parent(_X)) = _Black;
               _Color(_Parent(_Parent(_X))) = _Red;
               _Lrotate(_Parent(_Parent(_X))); }}
      _Color(_Root()) = _Black;
      return (iterator(_Z)); }
