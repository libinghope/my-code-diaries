using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MiniWPFCore.Interface
{
    public interface ISubscriber
    {
        void Subscribe(ISubscriber subscriber, IMyNotifyPropertyChanged publisher);
    }
}
